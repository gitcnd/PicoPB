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
    unsigned int encode_varint(char *,unsigned int);	// Returns the number of bytes used to store it
    unsigned int encode_varint(char *,int);
    unsigned int decode_varint(char *);
    int decode_svarint(char *);
  private:
    //int _memloc;
};

#endif

