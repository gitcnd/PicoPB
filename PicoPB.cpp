/*
  PicoPB.h v1.0 - An exceptionally lightweight Protocol-Buffers support lib which consumes no RAM and less than 1% flash
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#ifndef PicoPB_h
#include "PicoPB.h"


PicoPB::PicoPB(unsigned int unused)
{
  // no init needed
}

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
    buffer[bytes-1] &= 0x7F; /* Unset top bit on last byte */
  }
  return bytes+1;
}
unsigned int PicoPB::encode_varint(char *buffer,int value) {
  unsigned int zigzagged;
  if (value < 0)
     zigzagged = ~((unsigned int)value << 1);
  else
     zigzagged = (unsigned int)value << 1;

  return encode_varint(buffer, zigzagged);
}

unsigned int PicoPB::decode_varint(char *buffer)
{
  unsigned int result=0;
  unsigned char bitpos = 0;
  int i=0;
  do {
    result |= (unsigned int)(buffer[i] & 0x7F) << bitpos;
    bitpos += 7;
  } while (buffer[i++] & 0x80);
   
  return result;
}
int PicoPB::decode_svarint(char *buffer) {
  unsigned int value=decode_varint(buffer);
  if (value & 1) return (int)(~(value >> 1));
  else return (value >> 1);
}

#endif
