#include <IRLibRecvPCI.h>
IRrecvPCI myReceiver(2);  // Arduino UNO pin 2


void setup() {
  // Setup for serial comm
  Serial.begin(9600);
  myReceiver.enableIRIn();
}


void loop() {
  int skip = 0;
  uint16_t rx = 0;
 
  if (myReceiver.getResults()) {
    for (bufIndex_t i = 0; i < recvGlobal.recvLength; i++) {
      rx = recvGlobal.recvBuffer[i];
      if ((skip == 0) && (rx == 0))
      {
        skip = 1;
        continue;
      }
      skip =0;
      Serial.print(rx, DEC);
      Serial.print(F(","));
      }
    myReceiver.enableIRIn();
  }
}