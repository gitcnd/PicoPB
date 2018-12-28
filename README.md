# PicoPB
An exceptionally lightweight Protocol-Buffers support lib which consumes no RAM and less than 1% flash

WARNING: very basic early code!

# SYNOPSIS

```C
  #include <PicoPB.h>
  PicoPB PicoPB(0);
  byte buf[10];

  void setup() {
    unsigned int int_example=42;
    unsigned int num_bytes_to_encode= PicoPB.encode_varint(buf,int_example));
    unsigned int decoded_example=PicoPB.decode_varint(buf);
  }
```

# FUNCTIONS

```C
  // Most calls (except the ones returning numbers) will return the number of storage buffer bytes of the value
  encode_varint(buffer,value);	// Convert unsigned into varints and signed into svarints - returns #bytes taken to store it
  decode_varint(buffer);	// Gets it back
  decode_svarint(buffer);	// Gets back a signed result

  encode_string(char *buffer,char *input, unsigned int length);	// Store text or data
  encode_string(char *buffer,char *input); 			// calls encode_string with strlen(input)
  decode_string(char *buffer,char *output, unsigned int maxlen);// Get back stored text or data - NB: function returns the buffer space it took, not the length you got back
  encode_fixed32(char *buffer,float input);	// Store a float or something - note that on Arduino, float, double and long-double are all the same thing (4 bytes; 32bits)
  decode_fixed32(char *buffer);			// returns the number

  encode_fixed64(char *buffer,long double input);		// Coded, but don't work on arduino (which has no 64bit datatypes)
  decode_fixed64(char *buffer);
```


# HOW TO INSTALL

(Method 1)

1. Open a terminal (commandline, bash shell, whatever)
2. Change into your Arduino folder
```bash
   cd /Applications/Arduino.app/Contents/Java/libraries/
   (or)
   cd ~/Arduino/libraries/
```
3. grab and install this code
```bash
   git clone https://github.com/gitcnd/PicoPB.git
```
4. restart your arduino IDE
5. Choose File => Examples => PicoPB => PicoPB_example
6. Hit the "build" button and enjoy!

(Method 2) - see https://www.arduino.cc/en/Guide/Libraries

1. Download the ZIP of this repo: https://github.com/gitcnd/PicoPB/archive/master.zip
2. In your IDE, select Sketch -> Include Library -> Add .ZIP Library
3. Choose File => Examples => PicoPB => hello
4. Hit the "build" button and enjoy!

