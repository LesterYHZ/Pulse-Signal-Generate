double freq;
double offset;
double width;

unsigned long cycle_time;
unsigned long raising_edge;
unsigned long falling_edge;
unsigned long prev_micros;

#define TIME_CMP(X,Y,Z)(((X)-(Y))<(Z))

inline void setHigh(){
  PORTB = B00100000;
}

inline void setLow(){
  PORTB = B00000000;
}

void setup() {
  DDRB = B00100000;
  prev_micros = micros();

  while(1){
    freq = 0.5;
    width = 0.5;
    offset = 0.0;

    cycle_time = 1000000 / freq;
    raising_edge = (unsigned long)(offset*cycle_time);
    falling_edge = (unsigned long)((offset+width)*cycle_time);

    if(width+offset<1){
      while(TIME_CMP(micros(),prev_micros+raising_edge,cycle_time));setHigh();
      while(TIME_CMP(micros(),prev_micros+falling_edge,cycle_time));setLow();
    }else{
      while(TIME_CMP(micros(),prev_micros+falling_edge,cycle_time));setLow();
      while(TIME_CMP(micros(),prev_micros+raising_edge,cycle_time));setHigh();
    }
    prev_micros += cycle_time;
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
