#include <IRLibAll.h>
//Create Sender object
IRsend mySender;

void setup() {
}

void loop() {
  mySender.send(NEC, 0xFFFFFFFF);
}