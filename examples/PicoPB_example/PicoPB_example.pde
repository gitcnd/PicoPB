/*
  PicoPB_example.cpp v1.0 - shows how to use PicoPB lib
  (C) Copyright 2018 (GNU GENERAL PUBLIC LICENSE, Version 3) - Chris Drake <cdrake@cpan.org>
*/

#include <PicoPB.h>
#include <SerialID.h>
SerialIDset("\n#\tv2.03 " __FILE__ "\t" __DATE__ " " __TIME__);

PicoPB PicoPB(0); // 0 does nothing - we might need some switch in future?

#define BUFFSIZE 20
byte buf[BUFFSIZE];

void wipe(char *buf) {for(int i=0;i<BUFFSIZE;i++)buf[i]=0;}

void setup() {
  SerialIDshow(115200);
  int neg_example=-42;
  unsigned int int_example=42;
  float lazy_example=-42.42; // Lazy because the PB folk never optimized these - tch tch tch.
  char msg_example[]="Hello PicoPB!";

  wipe(buf); Serial.print(F("encoded int_example uses:")); Serial.print(PicoPB.encode_varint(buf,int_example)); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_varint(buf));

  int_example+=1234567;
  wipe(buf); Serial.print(F("encoded int_example uses:")); Serial.print(PicoPB.encode_varint(buf,int_example)); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_varint(buf));

  wipe(buf); Serial.print(F("encoded neg_example uses:")); Serial.print(PicoPB.encode_varint(buf,neg_example)); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_svarint(buf));

  neg_example-=12345;
  wipe(buf); Serial.print(F("encoded neg_example uses:")); Serial.print(PicoPB.encode_varint(buf,neg_example)); Serial.print(F("bytes. Decodes to:")); Serial.println(PicoPB.decode_svarint(buf));

} // setup

void loop() {
  Serial.println("Demo over");
  delay(5000);
}


