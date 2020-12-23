/*
   Piatto rotante sketch
   Code for stepper motor <= 200 steps

   DaveCalaway 2020 V1.0
*/

#include <Stepper.h>

const byte stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
byte rpm = 20;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


// -- SETUP --//
void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  myStepper.setSpeed(rpm);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("\n#####################");
  Serial.println("Benvenuto nel software del piatto rotante.");
}


// -- LOOP --//
void loop() {
  int degrees = 0;
  byte repeat = 1;

  while (degrees < 1 || degrees > 360) {
    Serial.print("\nInserisci un angolo di movimento tra 1 e 360: ");
    degrees = readSerial();
  }

  Serial.print("Inserisci un tempo, in secondi, d'attesa tra un angolo e l'altro: ");
  int secondTime = readSerial() * 1000;

  // 200 steps : 360 degrees = x steps : y degrees
  unsigned long _numStep = (200 * (unsigned long)degrees) / 360;
  if ( _numStep == 0 ) _numStep = 1;
  byte numStep = _numStep;

  while (repeat) {
    moveBase(numStep, secondTime);
    Serial.print("\nDigita '1' per ripetere: ");
    repeat = readSerial();
    if ( repeat == 1 ) repeat = 1;
    else repeat = 0;
  }
}


//-- READ SERIAL --//
int readSerial() {
  while (!Serial.available()) {
    // waiting serial
  }

  int num = Serial.parseInt();
  Serial.println(num);

  return num;
}


//-- MOVE BASE --//
// the func works with steps not with degrees
void moveBase(byte numStep, int secondTime) {
  byte steps = numStep;
  bool goOn = 1;

  while (goOn) {
    Serial.print("Mi muovo a: ");
    Serial.println((360 * (unsigned long)steps) / 200); // steps to degrees

    myStepper.step(numStep);
    //Serial.println(numStep);
    delay(secondTime);
    if ((steps + numStep) > stepsPerRevolution) {
      Serial.println("Torno a 0 gradi.");
      myStepper.step(stepsPerRevolution - steps); // return 0°
      goOn = 0;
    }
    steps = steps + numStep;
  }
}
