/*
  test_PicoPB.cpp v1.0 - testing all PicoPB encoding and decodings
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#include <PicoPB.h>
#include <SerialID.h>
SerialIDset("\n#\tv2.04 " __FILE__ "\t" __DATE__ " " __TIME__);

PicoPB PicoPB(0); // 0 does nothing - we might need some switch in future?

#define BUFFSIZE 200
//byte buf[BUFFSIZE];
char buf[BUFFSIZE];
// handy: https://www.arduino.cc/reference/en/

void wipe(char *buf) {for(int i=0;i<BUFFSIZE;i++)buf[i]=0;}

void l() { Serial.print(F(" l=")); wipe(buf); }
void p(char *s) { Serial.print(s); }
void ok() { Serial.println(F(" OK")); }
void ng() { Serial.println(F(" NG")); }

void setup() {
  SerialIDshow(115200);

  // 1byte
  boolean	va1=0;  boolean		va2=0;
  char		vb1=0;  char		vb2=0;
  unsigned char	vc1=0;  unsigned char	vc2=0;
  byte		vd1=0;  byte		vd2=0;
  uint8_t	vf1=0;  uint8_t		vf2=0;
  int8_t	vg1=0;  int8_t		vg2=0;

  // 2bytes
  int		vh1=0;  int		vh2=0;
  unsigned int	vi1=0;  unsigned int	vi2=0;
  word		vj1=0;  word		vj2=0;
  uint16_t	vk1=0;  uint16_t	vk2=0;
  int16_t	vl1=0;  int16_t		vl2=0;
  short		vm1=0;  short		vm2=0;
  unsigned short vn1=0; unsigned short	vn2=0;

  // 4bytes
  long		vo1=0;  long		vo2=0;
  unsigned long	vp1=0;  unsigned long	vp2=0;
  uint32_t	vq1=0;  uint32_t	vq2=0;
  int32_t	vr1=0;  int32_t		vr2=0;
  float		vs1=0;  float		vs2=0;
  double	vt1=0;  double		vt2=0;

  // 1+ bytes
  //byte 		vu1[]="Hello";byte 	vu2[]="xxxxx";
  char 		vu1[]="Hello";char 	vu2[]="xxxxx";

  p("boolean	"); Serial.print(va1); l(); Serial.print(PicoPB.encode_varint(buf,va1)); va2=PicoPB.decode_varint(buf); if(va2==va2)ok(); else ng();

  p(   "boolean		"); Serial.print(va1); l(); Serial.print(PicoPB.encode_varint(buf,va1)); va2=PicoPB.decode_varint(buf); if(va1==va2)ok(); else ng();
  va1=1; p(   "boolean		"); Serial.print(va1); l(); Serial.print(PicoPB.encode_varint(buf,va1)); va2=PicoPB.decode_varint(buf); if(va1==va2)ok(); else ng();

  p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1=vb1<<1 | 1; p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1=vb1<<1 | 1; p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1=vb1<<1 | 1; p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1=vb1<<1 | 1; p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1=vb1<<1 | 1; p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1=vb1<<1 | 1; p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1=vb1<<1 | 1; p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1=vb1<<1 | 1; p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1=vb1<<1 | 1; p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();
  vb1-=33;	  p(   "char		"); Serial.print(vb1,DEC); l(); Serial.print(PicoPB.encode_varint(buf,vb1)); vb2=PicoPB.decode_svarint(buf); if(vb1==vb2)ok(); else ng();

  p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else ng();
  vc1=vc1<<1 | 1; p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else ng();
  vc1=vc1<<1 | 1; p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else ng();
  vc1=vc1<<1 | 1; p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else {Serial.print(vc2);ng();}
  vc1=vc1<<1 | 1; p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else ng();
  vc1=vc1<<1 | 1; p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else ng();
  vc1=vc1<<1 | 1; p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else ng();
  vc1=vc1<<1 | 1; p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else ng();
  vc1=vc1<<1 | 1; p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else ng();
  vc1=vc1<<1 | 1; p(   "unsigned char	"); Serial.print(vc1); l(); Serial.print(PicoPB.encode_varint(buf,vc1)); vc2=PicoPB.decode_varint(buf); if(vc1==vc2)ok(); else ng();

  p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();
  vd1=vd1<<1 | 1; p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();
  vd1=vd1<<1 | 1; p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();
  vd1=vd1<<1 | 1; p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();
  vd1=vd1<<1 | 1; p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();
  vd1=vd1<<1 | 1; p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();
  vd1=vd1<<1 | 1; p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();
  vd1=vd1<<1 | 1; p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();
  vd1=vd1<<1 | 1; p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();
  vd1=vd1<<1 | 1; p(   "byte		"); Serial.print(vd1); l(); Serial.print(PicoPB.encode_varint(buf,vd1)); vd2=PicoPB.decode_varint(buf); if(vd1==vd2)ok(); else ng();

  p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();
  vf1=vf1<<1 | 1; p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();
  vf1=vf1<<1 | 1; p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();
  vf1=vf1<<1 | 1; p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();
  vf1=vf1<<1 | 1; p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();
  vf1=vf1<<1 | 1; p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();
  vf1=vf1<<1 | 1; p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();
  vf1=vf1<<1 | 1; p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();
  vf1=vf1<<1 | 1; p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();
  vf1=vf1<<1 | 1; p(   "uint8_t		"); Serial.print(vf1); l(); Serial.print(PicoPB.encode_varint(buf,vf1)); vf2=PicoPB.decode_varint(buf); if(vf1==vf2)ok(); else ng();

  p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1=vg1<<1 | 1; p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();
  vg1-=33;	  p(   "int8_t		"); Serial.print(vg1); l(); Serial.print(PicoPB.encode_varint(buf,vg1)); vg2=PicoPB.decode_svarint(buf); if(vg1==vg2)ok(); else ng();

  p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1++;	  p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1--;vh1--;	  p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else {Serial.print(vh2);ng();} // ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=vh1<<1 | 1; p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1-=33;	  p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vh2=PicoPB.decode_svarint(buf); if(vh1==vh2)ok(); else ng();
  vh1=32760;	  p(   "int		"); Serial.print(vh1); l(); Serial.print(PicoPB.encode_varint(buf,vh1)); vr2=PicoPB.decode_svarint(buf); if(vh1==vr2)ok(); else ng();
Serial.println(vr2);

  p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();
  vi1=vi1<<1 | 1; p(   "unsigned int	"); Serial.print(vi1); l(); Serial.print(PicoPB.encode_varint(buf,vi1)); vi2=PicoPB.decode_varint(buf); if(vi1==vi2)ok(); else ng();

  p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();
  vj1=vj1<<1 | 1; p(   "word		"); Serial.print(vj1); l(); Serial.print(PicoPB.encode_varint(buf,vj1)); vj2=PicoPB.decode_varint(buf); if(vj1==vj2)ok(); else ng();

  p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();
  vk1=vk1<<1 | 1; p(   "uint16_t	"); Serial.print(vk1); l(); Serial.print(PicoPB.encode_varint(buf,vk1)); vk2=PicoPB.decode_varint(buf); if(vk1==vk2)ok(); else ng();

  p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1=vl1<<1 | 1; p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();
  vl1-=33;	  p(   "int16_t		"); Serial.print(vl1); l(); Serial.print(PicoPB.encode_varint(buf,vl1)); vl2=PicoPB.decode_svarint(buf); if(vl1==vl2)ok(); else ng();

  p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1=vm1<<1 | 1; p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();
  vm1-=33;	  p(   "short		"); Serial.print(vm1); l(); Serial.print(PicoPB.encode_varint(buf,vm1)); vm2=PicoPB.decode_svarint(buf); if(vm1==vm2)ok(); else ng();

  p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();
  vn1=vn1<<1 | 1; p(   "unsigned short	"); Serial.print(vn1); l(); Serial.print(PicoPB.encode_varint(buf,vn1)); vn2=PicoPB.decode_varint(buf); if(vn1==vn2)ok(); else ng();

  p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1=vo1<<1 | 1; p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();
  vo1-=33;	  p(   "long		"); Serial.print(vo1); l(); Serial.print(PicoPB.encode_varint(buf,vo1)); vo2=PicoPB.decode_svarint(buf); if(vo1==vo2)ok(); else ng();

  p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();
  vp1=vp1<<1 | 1; p(   "unsigned long	"); Serial.print(vp1); l(); Serial.print(PicoPB.encode_varint(buf,vp1)); vp2=PicoPB.decode_varint(buf); if(vp1==vp2)ok(); else ng();

  p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();
  vq1=vq1<<1 | 1; p(   "uint32_t	"); Serial.print(vq1); l(); Serial.print(PicoPB.encode_varint(buf,vq1)); vq2=PicoPB.decode_varint(buf); if(vq1==vq2)ok(); else ng();

  p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1=vr1<<1 | 1; p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();
  vr1-=33;	  p(   "int32_t		"); Serial.print(vr1); l(); Serial.print(PicoPB.encode_varint(buf,vr1)); vr2=PicoPB.decode_svarint(buf); if(vr1==vr2)ok(); else ng();

  p(   "float		"); Serial.print(vs1); l(); Serial.print(PicoPB.encode_fixed32(buf,vs1)); vs2=PicoPB.decode_fixed32(buf); if(vs1==vs2)ok(); else ng();
  vs1=3.14159265359; p(   "float		"); Serial.print(vs1); l(); Serial.print(PicoPB.encode_fixed32(buf,vs1)); vs2=PicoPB.decode_fixed32(buf); if(vs1==vs2)ok(); else ng();
  vs1=-3.14159265359; p(   "float		"); Serial.print(vs1); l(); Serial.print(PicoPB.encode_fixed32(buf,vs1)); vs2=PicoPB.decode_fixed32(buf); if(vs1==vs2)ok(); else ng();
  p(   "double		"); Serial.print(vt1); l(); Serial.print(PicoPB.encode_fixed32(buf,vt1)); vt2=PicoPB.decode_fixed32(buf); if(vt1==vt2)ok(); else ng();
  vt1=3.14159265359; p(   "double		"); Serial.print(vt1); l(); Serial.print(PicoPB.encode_fixed32(buf,vt1)); vt2=PicoPB.decode_fixed32(buf); if(vt1==vt2)ok(); else ng();
  vt1=-3.14159265359; p(   "double		"); Serial.print(vt1); l(); Serial.print(PicoPB.encode_fixed32(buf,vt1)); vt2=PicoPB.decode_fixed32(buf); if(vt1==vt2)ok(); else ng();
  vt1=-31465359.123; p(   "double		"); Serial.print(vt1); l(); Serial.print(PicoPB.encode_fixed32(buf,vt1)); vt2=PicoPB.decode_fixed32(buf); if(vt1==vt2)ok(); else ng();
  vt1=0.000000314159; p(   "double		"); Serial.print(vt1); l(); Serial.print(PicoPB.encode_fixed32(buf,vt1)); vt2=PicoPB.decode_fixed32(buf); if(vt1==vt2)ok(); else ng();

  p(   "char 		"); Serial.print(vu1); l(); Serial.print(PicoPB.encode_string(buf,vu1)); PicoPB.decode_string(buf,vu2,sizeof(vu2)); if(strcmp(vu1,vu2)==0)ok(); else ng();



  ShowSizes();

} // setup


void loop() {
  Serial.println("\nYou're still here?");
  delay(3500);
  Serial.println("It's Over.");
  delay(2500);
  Serial.println("Go Home.");
  delay(5500);
  Serial.println("Go.");
  delay(10000);
}


void ShowSizes() {

 Serial.println("--- Variable type: Size in SRAM (bytes) ---");


 // C standard data type "unsigned int length 8 bits". 
 // Occupies one byte of memory.
 // http://arduino.cc/forum/index.php/topic,41590.0.html
 // http://en.wikipedia.org/wiki/Stdint.h#Fixed_width_integer_types
 Serial.print("uint8_t: ");
 Serial.println(sizeof(uint8_t));

 Serial.print("int8_t: ");
 Serial.println(sizeof(int8_t));

 // A boolean holds one of two values, true or false. 
 // Each boolean variable occupies one byte of memory.
 // http://arduino.cc/en/Reference/BooleanVariables
 Serial.print("boolean: ");
 Serial.println(sizeof(boolean));

 // A data type that takes up 1 byte of memory that stores a character value. 
 // Character literals are written in single quotes, like this: 'A' (for multiple
 // characters - strings - use double quotes: "ABC"). 
 // http://arduino.cc/en/Reference/Char
 Serial.print("char: ");
 Serial.println(sizeof(char));

 // An unsigned data type that occupies 1 byte of memory. Same as the byte datatype. 
 // The unsigned char datatype encodes numbers from 0 to 255.
 // For consistency of Arduino programming style, the byte data type is to be preferred. 
 // http://arduino.cc/en/Reference/UnsignedChar
 Serial.print("unsigned char: ");
 Serial.println(sizeof(unsigned char));
 
 // A byte stores an 8-bit unsigned number, from 0 to 255. 
 // http://arduino.cc/en/Reference/Byte
 Serial.print("byte: ");
 Serial.println(sizeof(byte));
 
 Serial.print("unsigned byte: ");
 Serial.println(sizeof(unsigned byte));
 
 // Integers are your primary datatype for number storage, and store a 2 byte value. 
 // This yields a range of -32,768 to 32,767 (minimum value of -2^15 and a maximum value of (2^15) - 1). 
 // http://arduino.cc/en/Reference/Int
 Serial.print("int: ");
 Serial.println(sizeof(int));

 // Unsigned ints (unsigned integers) are the same as ints in that they store a 2 byte value. 
 // Instead of storing negative numbers however they only store positive values, yielding a 
 // useful range of 0 to 65,535 (2^16) - 1). 
 // http://arduino.cc/en/Reference/UnsignedInt
 Serial.print("unsigned int: ");
 Serial.println(sizeof(unsigned int));

 // A word stores a 16-bit unsigned number, from 0 to 65535.
 // Same as an unsigned int. 
 // http://arduino.cc/en/Reference/Word
 Serial.print("word: ");
 Serial.println(sizeof(word));
 
 Serial.print("uint16_t: ");
 Serial.println(sizeof(uint16_t));
 
 Serial.print("int16_t: ");
 Serial.println(sizeof(int16_t));
 
 Serial.print("short: ");
 Serial.println(sizeof(short));
 
 Serial.print("unsigned short: ");
 Serial.println(sizeof(unsigned short));
 
 // Long variables are extended size variables for number storage, and store 32 bits (4 bytes), 
 // from -2,147,483,648 to 2,147,483,647. 
 // http://arduino.cc/en/Reference/Long 
 Serial.print("long: ");
 Serial.println(sizeof(long));

 // Unsigned long variables are extended size variables for number storage, and store 32 bits (4 bytes). 
 // Unlike standard longs unsigned longs won't store negative numbers, making their range from 0 
 // to 4,294,967,295 (2^32 - 1). 
 // http://arduino.cc/en/Reference/UnsignedLong
 Serial.print("unsigned long: ");
 Serial.println(sizeof(unsigned long));

 // Datatype for floating-point numbers, a number that has a decimal point.
 // Floating-point numbers can be as large as 3.4028235E+38 and as low as -3.4028235E+38. 
 // They are stored as 32 bits (4 bytes) of information. 
 // http://arduino.cc/en/Reference/Float
 Serial.print("float: ");
 Serial.println(sizeof(float));
 
 // Double precision floating point number. Occupies 4 bytes. 
 // The double implementation on the Arduino is currently exactly the same as the float, 
 // with no gain in precision.
 // http://arduino.cc/en/Reference/Double
 Serial.print("double: ");
 Serial.println(sizeof(double));
 
} // ShowSizes



