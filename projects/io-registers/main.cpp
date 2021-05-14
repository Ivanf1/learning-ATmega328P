#include <Arduino.h>

/**
 * DDRx
 *  - can be used to select the direction of the pin (input/output)
 * 
 * PORTx
 *  - when the pin is configured as input, PORTx can be used to
 *    activate/deactivate the pull-up resistor
 * 
 *  - when the pin is configured as output, PORTx can be used to
 *    drive the pin high or low
 * 
 * PINx
 *  - can be used to toggle the value of PORTx,
 *    indipendent on the value of DDRx
 * 
 *  - can be used to read the value of the pin
 */

void printIORegistersAddresses() {
  Serial.print("PINB address: ");
  Serial.println((int)&PINB, 16);
  Serial.print("DDRB address: ");
  Serial.println((int)&DDRB, 16);
  Serial.print("PORTB address: ");
  Serial.println((int)&PORTB, 16);
  Serial.print("PINC address: ");
  Serial.println((int)&PINC, 16);
  Serial.print("DDRC address: ");
  Serial.println((int)&DDRC, 16);
  Serial.print("PORTC address: ");
  Serial.println((int)&PORTC, 16);
  Serial.print("PIND address: ");
  Serial.println((int)&PIND, 16);
  Serial.print("DDRD address: ");
  Serial.println((int)&DDRD, 16);
  Serial.print("PORTD address: ");
  Serial.println((int)&PORTD, 16);
}

void setup() {
  Serial.begin(115200);
  printIORegistersAddresses();
}

void loop() {}