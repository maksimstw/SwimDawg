
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
  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1,addresses[1]);
  radio.startListening();
}

void loop() {  
    if( radio.available()){
                                                           // Variable for the received timestamp
      while (radio.available()) {                          // While there is data ready
        radio.read( &myData, sizeof(myData) );             // Get the payload
      }
      Serial.println(myData.value);
   }
} 
