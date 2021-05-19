#include <Arduino.h>

// interrupt vector handler when timer overflows
ISR(TIMER1_OVF_vect) {
  // toggle pin 2
  PIND = (1 << PIND2);
}

void setup() {
  // set pin 2 as output
  DDRD = (1 << DDD2);

  // not using anything from this register
  TCCR1A = 0;

  // count every 256 cycles
  // roughly every 1 second
  TCCR1B = (1 << CS12);

  // generate an interrupt when the timer overflows
  TIMSK1 = (1 << TOIE1);
}

void loop() {}