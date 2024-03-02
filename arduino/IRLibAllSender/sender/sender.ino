#include <IRLibAll.h>
//Create Sender object
IRsend mySender;
//Create a receiver object to listen on pin 2 

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  Serial.println(F("Ready to receive IR signals"));
}

void loop() {
  mySender.send(NEC, 0xFFFFFFFF);
}