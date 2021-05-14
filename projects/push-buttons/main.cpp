#include <Arduino.h>

void setup() {
  // set pins D2 and D3 as input
  DDRD = 0b11110011;
  // set the pull-up resistor for pins D2 and D3
  PORTD = 0b00001100;
  Serial.begin(115200);
}

static byte value = 0;
static byte newValue = 0;

void loop() {
  /**
   * get the readings from all the pins and
   * mask the pins we don't care about
   */
  newValue = 0b00001100 & PIND;

  if (newValue != value) {
    /**
     * print bits one by one
     * printing with Serial.print in base 2
     * would not print leading zeroes
     */
    for (int8_t i = 7; i >= 0; i--) {
      Serial.print(bitRead(newValue, i));
    }
    Serial.println();
    value = newValue;
  }
}