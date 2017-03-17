/*
 * Drive a Stepper Motor ( uni or bi polar ), when button is pressed, forword to XStep, little Break, 
 * and back to -Xstep.
 * 
 * Davide Gariselli 
 * 
 * No external libray needed.
 * This example code is in the public domain.
 */

#include <Stepper.h>

#define pinButton 2
#define Delay 1000
#define Speed 60 //rpm = Revolutions per minute
#define Step 10

bool button = 1;
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins
Stepper myStepper(stepsPerRevolution, 3, 5, 6, 9);

void setup() {
  pinMode(pinButton, INPUT);
  myStepper.setSpeed(Speed); //rpm
  Serial.begin(9600);
}

void loop() {
  if ( analogRead(pinButton) == 0 ) {
    delay(20);
    Serial.println("clockwise: " + Step);
    myStepper.step(Step);
    delay(Delay);

    Serial.println("anti-clockwise: -" + Step);
    myStepper.step(-Step);
    delay(20);
  }
}

