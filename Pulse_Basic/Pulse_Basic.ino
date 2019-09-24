void setup() {
  // Generate pulse signal on pin 13
  pinMode(13,OUTPUT);
}

void loop() {
  // Period = 2 sec
  // Duty Cycle = 0.5
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}
