void setup() {
  // Frequency = 100 Hz
  // Duty Cycle = 0.5
  pinMode(3,OUTPUT);
  pinMode(11,OUTPUT);

  TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS22) | _BV(CS21) | _BV(CS20);

  // freq = 16MHz/1024/(OCR2A+1) = 100 --> OCR2A = 155
  OCR2A = 155;
  // Duty Cycle 50%
  OCR2B = 77;
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
