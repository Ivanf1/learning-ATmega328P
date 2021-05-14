#include <Arduino.h>

#define DELAY_MS 200

void setup() {
  DDRD = 0xff;
  PORTD = 0xff;
}

void loop() {
  for (uint8_t i = 0; i < 8; i++) {
    PIND |= (1 << i);
    delay(DELAY_MS);
  }

  for (uint8_t i = 0; i < 6; i++) {
    PIND |= (PIND >> 1);
    delay(DELAY_MS);
  }
}