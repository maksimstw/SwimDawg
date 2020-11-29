
#include <SPI.h>
#include "RF24.h"

byte addresses[][6] = {"1Node","2Node"};

bool radioNumber = 0;

RF24 radio(7,8);

bool role = 0;

struct dataStruct{
  float value;
}myData;

void setup() {

  Serial.begin(9600);  
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  
  if(radioNumber){
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
  }else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
  
  radio.startListening();
}

void loop() {
  if ( role == 0 )
  {
    
    if( radio.available()){
                                                           // Variable for the received timestamp
      while (radio.available()) {                          // While there is data ready
        radio.read( &myData, sizeof(myData) );             // Get the payload
      }
      Serial.println(myData.value);
   }
 }
} // Loop
