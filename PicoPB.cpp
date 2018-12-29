/*
  PicoPB.h v1.0 - An exceptionally lightweight Protocol-Buffers support lib which consumes no RAM and less than 1% flash
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>

  See https://developers.google.com/protocol-buffers/docs/encoding

  Protocol-Buffers (PB) are a binary data format where elements are stored using TAG:VALUE triplets (TAG consists of a 5bit ID and a 3 bit field-type).
  integers are stored a varints (efficient space-savers).  strings as a varint length and their bytes.  floats are stupidly just stored as-is - your fault for using them I guess.

  The code below just lets you put PB bytes into a buffer - so if you're happy to skip the bloat-fest front-end stuff that PB has become, and just manually store your data (which
  will suit 99% of IoT use cases), this lib is for you. [yes, you can still enjoy the bloatfest on the other (internet-server) end when you're processing your IoT data of course]

*/

#ifndef PicoPB_h
#include "PicoPB.h"
#include <string.h> // memcpy

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif



PicoPB::PicoPB(unsigned int unused)
{
  // no init needed
}


// This gets used for unsigned ints
// CAUTION - unsigned int math can trip you up - code with care.
unsigned int PicoPB::encode_varint(char *buffer,uint32_t value) {
  unsigned int bytes=0;

  if (value <= 0x7F) {
    buffer[0]=value;
  } else {
    while (value) {
      buffer[bytes]=((value & 0x7F) | 0x80);
      value >>= 7;
      bytes++;
    }
    bytes--;
    buffer[bytes] &= 0x7F; // Unset top bit on last byte
  }
  return bytes+1;
} //encode_varint


unsigned int PicoPB::encode_varint(char *buffer,unsigned int value) {
  uint32_t newval=value;
  return encode_varint(buffer,newval); // copy the 16bit data into 32bit and use the 32bit code
}
unsigned int PicoPB::encode_varint(char *buffer,unsigned char value) {
  uint32_t newval=value;
  return encode_varint(buffer,newval); // copy the 16bit data into 32bit and use the 32bit code
}

/*

// CAUTION - unsigned int math can trip you up - code with care.
unsigned int PicoPB::encode_varint(char *buffer,unsigned int value) {
  unsigned int bytes=0;

  if (value <= 0x7F) {
    buffer[0]=value;
  } else {
    while (value) {
      buffer[bytes]=((value & 0x7F) | 0x80);
      value >>= 7;
      bytes++;
    }
    bytes--;
    buffer[bytes] &= 0x7F; // Unset top bit on last byte
  }
  return bytes+1;
} //encode_varint

*/

// Use this to decode unsigned ints
uint32_t PicoPB::decode_varint(char *buffer) {
  uint32_t result=0;
  uint32_t qtmp=0;
  unsigned char bitpos = 0;
  int i=0;
  do {
    qtmp=buffer[i] & 0x7F; qtmp=qtmp<<bitpos;
    result |= qtmp;
    //result |= (buffer[i] & 0x7F) << bitpos;
    bitpos += 7;
  } while (buffer[i++] & 0x80);
   
  return result;
} // decode_varint

unsigned int PicoPB::decode_varint(uint8_t *buffer, uint32_t *result) { // returns length in bytes
  *result=0;
  unsigned char bitpos = 0;
  uint32_t qtmp=0;
  unsigned int i=0;
  do {
//Serial.print(" r=0x");Serial.print(buffer[i],HEX);
    qtmp=buffer[i] & 0x7F; qtmp=qtmp<<bitpos;
    *result |= qtmp;
    //*result |= (buffer[i] & 0x7F) << bitpos; // arduino cannot << properly
//Serial.print(" a=");Serial.print(*result);
    bitpos += 7;
  } while (buffer[i++] & 0x80);
//  Serial.print(" i=");Serial.println(i);  
  return i;
} // decode_varint

unsigned int PicoPB::decode_varint(uint8_t *buffer, uint16_t *result) {	// returns length in bytes
  uint32_t newresult=*result;
  unsigned int ret=decode_varint(buffer,&newresult);
  *result=newresult;
  return ret;
}

// This will be used if your ints are signed - NOTE - do not use signed-ints if you don't need them.
// CAUTION - unsigned int math can trip you up - code with care.
unsigned int PicoPB::encode_varint(char *buffer,int32_t value) {
  uint32_t zigzagged;
  if (value < 0)
     zigzagged = ~((uint32_t)value << 1);
  else
     zigzagged = (uint32_t)value << 1;

  return encode_varint(buffer, zigzagged);
} //encode_varint

unsigned int PicoPB::encode_varint(char *buffer,int value) {
  int32_t newval=value;
  return encode_varint(buffer,newval); // copy the 16bit data into 32bit and use the 32bit code
}

// Use this to decode signed ints
int32_t PicoPB::decode_svarint(char *buffer) {
  uint32_t value=decode_varint(buffer);
  //if (value & 1){value/=2; return -value;} else {value/=2; return value;}
  if (value & 1) return (int32_t)(~(value >> 1)); else return (value >> 1);
} //decode_svarint

//int16_t PicoPB::decode_svarint(char *buffer) {
//  uint32_t value=decode_varint(buffer);
//  int16_t ret;
//  if (value & 1){value/=2; ret=-value; return ret} else {value/=2; ret=value; return ret;}
//}



// Use these for strings and stuff
unsigned int PicoPB::encode_string(char *buffer,char *input, unsigned int length) {
  unsigned int lenlen=encode_varint(buffer,length); // put the length of the input into the output buffer
  memcpy(&buffer[lenlen],input,length);
  return lenlen+length;
} //encode_string
unsigned int PicoPB::encode_string(char *buffer,char *input) {return encode_string(buffer,input,strlen(input));} // for caller ease

// Use this to decode strings
unsigned int PicoPB::decode_string(char *buffer,char *output, unsigned int maxlen) {
  uint32_t result=0;
  unsigned char bitpos = 0;
  long lenlen=0;
  uint32_t qtmp=0;
  do {
    qtmp=buffer[lenlen] & 0x7F; qtmp=qtmp<<bitpos;
    result |= qtmp;
    //result |= (unsigned int)(buffer[lenlen] & 0x7F) << bitpos;
    bitpos += 7;
  } while (buffer[lenlen++] & 0x80);
  if(result<maxlen){output[result]=0;maxlen=result;} // terminate if theres room, plus, remember the full string length for returning shortly (so we re-use maxlen as the (posisbly shorter) lengh in memcpy shortly)
  memcpy(output,&buffer[lenlen],maxlen);
  return result+lenlen; // returns the number of bytes that this string used in the buffer - even if the output was too small to recieve it all
} // decode_string
unsigned int PicoPB::decode_string(byte *buffer,byte *output, unsigned int maxlen) { return decode_string(buffer,output,maxlen); }

// Caution: these require the "endianness" of your IoT platform to match the PB specs
unsigned int PicoPB::encode_fixed32(char *buffer,float input) {
  ((float *)buffer)[0]=input;

  return sizeof(float);
} //encode_fixed32
float PicoPB::decode_fixed32(char *buffer) {
  return ((float *)buffer)[0];
} //decode_fixed32
//unsigned int PicoPB::encode_fixed32(char *buffer,double input) { ((double *)buffer)[0]=input; return sizeof(double); } // double is also 4 bytes on Arduino!
//double PicoPB::decode_fixed32(char *buffer) { return ((double *)buffer)[0]; }

unsigned int PicoPB::encode_fixed64(char *buffer,long double input) {
  ((long double *)buffer)[0]=input;
  return sizeof(long double); // caution: also 4 bytes on arduino
} //encode_fixed64
long double PicoPB::decode_fixed64(char *buffer) {
  return ((long double *)buffer)[0];
} //decode_fixed64


#endif

/*
 *	varint tags are PB_WT_VARINT.  2 fixed tags of 32 and 64 for floats etc (PB_WT_32BIT).  rest are PB_WT_STRING
 *

typedef enum {
  PB_WT_VARINT = 0,
  PB_WT_64BIT  = 1,
  PB_WT_STRING = 2,
  PB_WT_32BIT  = 5
} pb_wire_type_t;



bool checkreturn pb_encode_fixed32(pb_ostream_t *stream, const void *value)
{   
    uint32_t val = *(const uint32_t*)value;
    pb_byte_t bytes[4];
    bytes[0] = (pb_byte_t)(val & 0xFF); 
    bytes[1] = (pb_byte_t)((val >> 8) & 0xFF);
    bytes[2] = (pb_byte_t)((val >> 16) & 0xFF);
    bytes[3] = (pb_byte_t)((val >> 24) & 0xFF);
    return pb_write(stream, bytes, 4);
}

bool checkreturn pb_encode_fixed64(pb_ostream_t *stream, const void *value)
{   
    uint64_t val = *(const uint64_t*)value;
    pb_byte_t bytes[8];
    bytes[0] = (pb_byte_t)(val & 0xFF); 
    bytes[1] = (pb_byte_t)((val >> 8) & 0xFF);
    bytes[2] = (pb_byte_t)((val >> 16) & 0xFF);
    bytes[3] = (pb_byte_t)((val >> 24) & 0xFF);
    bytes[4] = (pb_byte_t)((val >> 32) & 0xFF);
    bytes[5] = (pb_byte_t)((val >> 40) & 0xFF);
    bytes[6] = (pb_byte_t)((val >> 48) & 0xFF);
    bytes[7] = (pb_byte_t)((val >> 56) & 0xFF);
    return pb_write(stream, bytes, 8);
}


bool pb_decode_fixed32(pb_istream_t *stream, void *dest)
{
    pb_byte_t bytes[4];

    if (!pb_read(stream, bytes, 4))
        return false;
     
    *(uint32_t*)dest = ((uint32_t)bytes[0] << 0) |
                       ((uint32_t)bytes[1] << 8) |
                       ((uint32_t)bytes[2] << 16) |
                       ((uint32_t)bytes[3] << 24);
    return true;
}

bool pb_decode_fixed64(pb_istream_t *stream, void *dest)
{
    pb_byte_t bytes[8];

    if (!pb_read(stream, bytes, 8))
        return false;
    
    *(uint64_t*)dest = ((uint64_t)bytes[0] << 0) |
                       ((uint64_t)bytes[1] << 8) |
                       ((uint64_t)bytes[2] << 16) | 
                       ((uint64_t)bytes[3] << 24) |
                       ((uint64_t)bytes[4] << 32) |
                       ((uint64_t)bytes[5] << 40) |
                       ((uint64_t)bytes[6] << 48) |
                       ((uint64_t)bytes[7] << 56);
    
    return true;
}


static bool checkreturn pb_dec_string(pb_istream_t *stream, const pb_field_t *field, void *dest)
{
    uint32_t size;
    size_t alloc_size;
    bool status;
    if (!pb_decode_varint32(stream, &size))
        return false;
   
    // Space for null terminator
    alloc_size = size + 1;
   
    if (alloc_size < size)
        PB_RETURN_ERROR(stream, "size too large");
   
    if (PB_ATYPE(field->type) == PB_ATYPE_POINTER)
    {
#ifndef PB_ENABLE_MALLOC
        PB_RETURN_ERROR(stream, "no malloc support");
#else
        if (!allocate_field(stream, dest, alloc_size, 1))
            return false;
        dest = *(void**)dest;
#endif
    }
    else
    {
        if (alloc_size > field->data_size)
            PB_RETURN_ERROR(stream, "string overflow");
    }
   
    status = pb_read(stream, (pb_byte_t*)dest, size);
    *((pb_byte_t*)dest + size) = 0;
    return status;
}




 *	
 *
 *
 *
 *
 *
 */
