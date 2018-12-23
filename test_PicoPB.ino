/*
  PicoPB_example.cpp v1.0 - shows how to use PicoPB lib
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#include <PicoPB.h>
#include <CRC32.h>
CRC32 crc; // was: Sketch uses 2686 bytes (8%) of program storage space. Maximum is 30720 bytes. / Global variables use 222 bytes (10%) of dynamic memory, leaving 1826 bytes for local variables. Maximum is 2048 bytes.
// now: Sketch uses 2708 bytes (8%) of program storage space. Maximum is 30720 bytes. / Global variables use 226 bytes (11%) of dynamic memory, leaving 1822 bytes for local variables. Maximum is 2048 bytes.


#include <SerialID.h>
SerialIDset("\n#\tv2.03 " __FILE__ "\t" __DATE__ " " __TIME__);

PicoPB PicoPB(0); // 0 does nothing - we might need some switch in future?

#define BUFFSIZE 20
byte buf[BUFFSIZE];
byte tst[BUFFSIZE];

void wipe(char *buf) {for(int i=0;i<BUFFSIZE;i++)buf[i]=65;}

void setup() {
  SerialIDshow(115200);
  int neg_example=-42;
  unsigned int int_example=42;
  float lazy_example=-42.42; // Lazy because the PB folk never optimized these - tch tch tch.
  double big_example=-424242.424242;
  long double huge_example=-424247.724242;
  char msg_example[]="Hello PicoPB!";

  wipe(buf); Serial.print(F("encoded int_example uses:")); Serial.print(PicoPB.encode_varint(buf,int_example)); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_varint(buf));


  int_example+=12345;
  wipe(buf); Serial.print(F("encoded int_example uses:")); Serial.print(PicoPB.encode_varint(buf,int_example)); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_varint(buf));

  uint32_t checksum=crc.calculate(buf,4);
  Serial.print(F("checksum:")); Serial.println(checksum);
  

  wipe(buf); Serial.print(F("encoded neg_example uses:")); Serial.print(PicoPB.encode_varint(buf,neg_example)); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_svarint(buf));

  neg_example-=12345;
  wipe(buf); Serial.print(F("encoded neg_example uses:")); Serial.print(PicoPB.encode_varint(buf,neg_example)); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_svarint(buf));


  wipe(buf); Serial.print(F("encoded msg_example uses:")); Serial.print(PicoPB.encode_string(buf,msg_example),DEC); Serial.print(F("bytes. Decodes to:")); wipe(tst); PicoPB.decode_string(buf,tst,BUFFSIZE); Serial.println((char *)tst);


  wipe(buf); Serial.print(F("encoded lazy_example uses:")); Serial.print(PicoPB.encode_fixed32(buf,lazy_example),DEC); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_fixed32(buf));


  //wipe(buf); Serial.print(F("encoded big_example uses:")); Serial.print(PicoPB.encode_fixed32(buf,big_example),DEC); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_fixed32(buf));


  long double rec=0;
  wipe(buf); Serial.print(F("encoded huge_example uses:")); Serial.print(PicoPB.encode_fixed64(buf,huge_example),DEC); Serial.print(F("bytes. Decodes to:")); rec=PicoPB.decode_fixed64(buf); if(rec==huge_example)Serial.println(F("OK"));
  

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
