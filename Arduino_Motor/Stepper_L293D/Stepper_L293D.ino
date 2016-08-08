/*
  Davide Gariselli - Version 0.1 - 2/08/2016
  This sketch is made for Arduino to drive Stepper motor with L293D.
  For motors with 5-way only.
  
  Datasheet: http://goo.gl/cQYo95
  No library needed.
*/

#include <Stepper.h>

//---------------------------- IMPOSTAZIONI ---------------------------------
// m_steps è il numero del passi posseduto dal motore 
#define m_steps 500
// steps è il numero di passi che farà il motore
#define steps 50
//---------------------------------------------------------------------------

int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;
const int buttonPin = 2;
bool buttonState = 0;

// The first parameter is the number of 'steps'
// that the motor will take to complete one revolution.
Stepper motor(m_steps, in1Pin, in2Pin, in3Pin, in4Pin);

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  motor.setSpeed(20); //rpm
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if ( buttonState == 0 ) {
    delay(20);
    motor.step(steps);
    delay(1000);
    motor.step(-steps);
  }
}
