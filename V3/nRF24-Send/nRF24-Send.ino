#include <SPI.h>
#include "RF24.h"

byte addresses[][6] = {"1Node","2Node"};

RF24 radio(7,8);

struct dataStruct{
  float value;
}myData;

void setup() {

  Serial.begin(9600);
  
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(addresses[1]);
  radio.openReadingPipe(1,addresses[0]); 
  myData.value = 1.22;
}

void loop() {   
   radio.stopListening();                                    // First, stop listening so we can talk.
   Serial.println(F("Now sending"));
   if (!radio.write( &myData, sizeof(myData) )){
      Serial.println(F("failed"));
   }
   Serial.println(myData.value);
   delay(1000);
}
