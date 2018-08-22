/* That example born to understand how the Register manipulation works
   on ATMega328 ( Arduino Uno ).

   Register PORTB |7|6|5 | 4| 3| 2|1|0|
           pin    |X|X|13|12|11|10|9|8|

   Register PORTC | 7| 6| 5| 4| 3| 2| 1| 0|
            pin   |ND|ND|A5|A4|A3|A2|A1|A0|

   Register PORTD |7|6|5|4|3|2|1|0|
            pin   |7|6|5|4|3|2|1|0|

   DaveCalaway
*/

#include <Arduino.h>

#define ledPin 13
#define buttonPin 3


void setup() {
  //pinMode(ledPin, OUTPUT);
  DDRB = B00100000;

  //pinMode(buttonPin,INPUT_PULLUP);
  PORTD = B00001000;
}

void loop() {
  //bool button = digitalRead(buttonPin);
  bool button = ( PIND & (1 << 3) ) >> 3;

  if (button == 0) {
    //digitalWrite(ledPin, HIGH);
    PORTB = (1 << 5) | PORTB;
  }
  else {
    //digitalWrite(ledPin, LOW);
    PORTD = ~(1 << 5) & PORTB;
  }
}

