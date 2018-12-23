/*
  PicoPB.h v1.0 - An exceptionally lightweight Protocol-Buffers support lib which consumes no RAM and less than 1% flash
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#ifndef PicoPB_h
#define PicoPB_h

class PicoPB
{
  public:
    PicoPB(unsigned int);
    unsigned int encode_varint(char *buffer, unsigned int input);	// Returns the number of bytes used to store it
    unsigned int encode_varint(char *buffer, int input);		//  "
    unsigned int decode_varint(char *buffer);			// Returns the unsigned int
    int decode_svarint(char *);				// Returns the signed int

    // All return the number of buffer-bytes used:-
    unsigned int encode_string(char *buffer,char *input, unsigned int length);
    unsigned int encode_string(char *buffer,char *input); // calls encode_string with strlen(input)
    unsigned int decode_string(char *buffer,char *output, unsigned int maxlen);
    unsigned int encode_fixed32(char *buffer,float input);
    //unsigned int encode_fixed32(char *buffer,double input);
    float decode_fixed32(char *buffer);
    //double decode_fixed32(char *buffer);

    unsigned int encode_fixed64(char *buffer,long double input);
    long double decode_fixed64(char *buffer);


  private:
    //int _memloc;
};

#endif

