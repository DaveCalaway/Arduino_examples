/*
 * Primo esempio PWM:
 * controllo luminosità led tramite comando PWM.
 * 
 */
int ledPin = 1;    // LED connected to digital pin 9

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // fade in from min to max in increments of 5 points
  // sets the value (range from 0 to 255)
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // Funzione PWM
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points
  // sets the value (range from 0 to 255)
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // funzione PWM
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}

/*
 * Domanda:
 * perchè non succede nulla se uso il pin 13?
 * Quali pin posso utilizzare e quali no?
 */
