#include <IRLibRecvPCI.h>
IRrecvPCI myReceiver(2);  // Arduino UNO pin 2


void setup() {
  // Setup for serial comm
  Serial.begin(9600);
  myReceiver.enableIRIn();
}


void loop() {
  if (myReceiver.getResults()) {
    for (bufIndex_t i = 1; i < recvGlobal.recvLength; i++) {
      Serial.print(recvGlobal.recvBuffer[i], DEC);
      Serial.print(F(","));
      }
    myReceiver.enableIRIn();
  }
}