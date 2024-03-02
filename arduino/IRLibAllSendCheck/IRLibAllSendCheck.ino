#include <IRLibAll.h>
//Create Input String
String input_str = "";
//Create Sender object
IRsend mySender;
//Create a receiver object to listen on pin 2
IRrecvPCI myReceiver(2);   
//Create a decoder object 
IRdecode myDecoder;   

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
}

void loop() {
  char in_char = "";
  while (Serial.available()){
    in_char = Serial.read();
    if (int(in_char) != -1)
      input_str += in_char;
  }
  if (in_char =='\n'){
    if (input_str == "0\n") {
      //send a code every time a character is received from the serial port
      // Treadmill code for increase speed 847B40BF
      mySender.send(NEC, 0x847B40BF);
    }
    if (input_str == "1\n") {
      //send a code every time a character is received from the serial port
      // Treadmill code for decrease speed 847B40BF
      mySender.send(NEC, 0x847BC03F);
    }
    if (input_str == "2\n") {
      //send a code every time a character is received from the serial port
      // Treadmill code for power 
      mySender.send(NEC, 0x847B807F);
    }
    input_str = "";
  }
  if (myReceiver.getResults()) {
    myDecoder.decode();           //Decode it
    myDecoder.dumpResults(true);  //Now print results. Use false for less detail
    myReceiver.enableIRIn();      //Restart receiver
  }
}