#include <Arduino.h>

// Pin Change Interrupt 0 vector handler
ISR(PCINT0_vect) {
  Serial.println("hello");
}

void setup() {
  // set pin 8 as input and all the other pins as output
  DDRB = 0xff | (0 << DDB0);
  // set the pull-up resistor for pin 8
  PORTB = (1 << PORTB0);

  /**
   * enable Pin Change Interrupt 0
   * any change on any enabled PCINT[7:0] pin
   * will cause an interrupt
   */
  PCICR |= (1 << PCIE0);

  // enable Pin Change Interrupt on pin 8
  PCMSK0 |= (1 << PCINT0);

  Serial.begin(115200);
}

void loop() {}