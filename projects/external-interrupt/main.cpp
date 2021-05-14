#include <Arduino.h>

/**
 * Generating an external interrupt
 * via a push button
 */

// INT0 interrupt vector handler
ISR(INT0_vect) {
  Serial.println("Interrupt occurred");
}

void setup() {
  // set pin 2 as input and all other pins as output
  DDRD = 0xff | (0 << DDD2);
  // set the pull-up resistor for pin 2
  PORTD = (1 << PORTD2);

  // enable the external pin interrupt for pin 2 (INT0)
  EIMSK = (1 << INT0);
  // generate an interrupt request on the rising edge of INT0
  EICRA = (1 << ISC01) | (1 << ISC00);
  Serial.begin(115200);
}

void loop() {}