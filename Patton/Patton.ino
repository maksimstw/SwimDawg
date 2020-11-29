#define HWSERIAL Serial1  // Create Hardware Serial port 2
//********************************************************
//    Setup (runs once)
//********************************************************
void setup() {
  // initialize serial communications at 9600 bits per second for each port:
  Serial.begin(9600);
  HWSERIAL.begin(9600);
}
//********************************************************
//    Recieve Hardware Serial data
//********************************************************
void getHWSerial() {
  while (HWSERIAL.available() == 0);  // wait until there is data in the buffer
  if (HWSERIAL.available() > 0) { //if there is data in the serial buffer.....
    Serial.println(HWSERIAL.readStringUntil(10));    // Print Collected data until a line feed (Char 10) is detected
  }
}
//********************************************************
//    Send Hardware Serial data
//********************************************************
void sendHWSerial() {
  int sensorValue = analogRead(A0); // read the input on analog pin 0:
  Serial.println(sensorValue); // print out the value you read:
  HWSERIAL.println(sensorValue); // Send data to Hardware Serial
  delay(100);
}
//********************************************************
//      Main Loop (loops forever)
//********************************************************
void loop() {
//  getHWSerial();
  sendHWSerial();
  delay(10);        // delay in between reads for stability
}

