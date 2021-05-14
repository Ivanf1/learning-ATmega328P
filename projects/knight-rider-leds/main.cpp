#include <Arduino.h>

#define DELAY_MS 200

/**
 * DDRD, PORTD and PIND refer to pins D0 to D7
 */

void setup() {
  // configuring the pins as output
  DDRD = 0xff;
  // drive high all the pins 
  PORTD = 0xff;
}

void loop() {
  for (uint8_t i = 0; i < 8; i++) {
    /**
     * Writing a one to PIND toggles the value of PORTD
     * indipendent on the value of DDRD
     */
    PIND |= (1 << i);
    delay(DELAY_MS);
  }

  for (uint8_t i = 0; i < 6; i++) {
    PIND |= (PIND >> 1);
    delay(DELAY_MS);
  }
}