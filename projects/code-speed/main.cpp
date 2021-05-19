#include <Arduino.h>

/**
 * By setting the timer to 0 and the
 * prescaler to 1, we can measure how many
 * clock cycles it takes to run some code.
 * We can the use the clock cycles to measure
 * the time of execution of the code under test
 * in microseconds
 * 
 * In this example we compare toggling a pin
 * connected to an led with digitalWrite and
 * port manipulation
 */

void setup() {
  Serial.begin(115200);
  DDRD = (1 << DDD2);

  // set prescaler to 1 (no prescaling)
  TCCR1B = (1 << CS10);

  /**
   * since this timer is 16-bit 
   * we would need to write to
   * TCNT1H and TCNT1L simultaneously
   * but in our case the compiler will handle
   * the 16-bit access, se we can use TCNT1
   * to refer to both the High 8-bits and Low 8-bits
   */
  TCNT1 = 0;

  // toggle the pin
  digitalWrite(2, HIGH);
  digitalWrite(2, LOW);

  uint16_t cycles = TCNT1;
  Serial.println(cycles-1);

  /**
   * since the clock frequency is 16MHz there are
   * 16 million cycles a second. Knowing that a microsecond
   * is a millionth of a second, we can divide the number
   * of cycles by 16 and get the number of microseconds it
   * took the code to run
   */
  Serial.println((float)(cycles-1)/16);


  // with direct port access
  TCNT1 = 0;

  // toggle the pin
  PIND = (1 << PIND2);
  PIND = (1 << PIND2);

  cycles = TCNT1;
  Serial.println(cycles-1);
  Serial.println((float)(cycles-1)/16);
}

void loop() {}