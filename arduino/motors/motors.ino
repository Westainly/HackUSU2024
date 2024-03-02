void setup() {
  // LED_BUILTIN : PIN 13 for data output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Write to high to turn motor on through transistor.
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  // Write to low to turn motor off through transistor
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
