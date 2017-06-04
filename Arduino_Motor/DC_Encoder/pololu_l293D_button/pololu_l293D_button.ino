/* Dave Calaway 03/05/2017 - V0.5
   GIT: https://goo.gl/O5A4XS

   MicroControllers, same code: 
   - Pro_mini_SparkFun https://goo.gl/YHEZj8 
   - Arduino 
   
   Control DC motor with encoder and L293D. Press button for start.
   The sketch print the angles in real time.

   No library needed.
*/

#include <SoftwareSerial.h>
//---------------------------- IMPOSTAZIONI ---------------------------------
// numero di gradi da fare, avanti ed indietro. 850 quasi 360°
#define gradi 850
// attesa prima del ritorno a 0, 1000 = 1sec
#define pausa 1000
//Velocità motori 0-255
#define Speed 50
//---------------------------------------------------------------------------

// Button's pin
const int buttonPin = 2;
bool buttonState = 0;

// the motor will start at clockwise
int clockwise = Speed;
int anticlockwise = 0;

/* L293D: motor terminals and enable pin */

int motorRightPositive = 5; // must PWM
int motorRightNegative = 6; // must PWM
int motorRightEnable_pin = 9;

/*Encoder connect pins */

int encoder0PinA1 = 7;
int encoder0PinB1 = 8;
int encoder0Pos1 = 0;
int encoder0PinALast1 = LOW;
int n1 = LOW;
bool en = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode (encoder0PinA1, INPUT);
  pinMode (encoder0PinB1, INPUT);
  Serial.begin (115200);

  pinMode (motorRightPositive, OUTPUT);
  pinMode (motorRightNegative , OUTPUT);
  pinMode(motorRightEnable_pin, OUTPUT);
}

void loop() {
  //read button state
  buttonState = digitalRead(buttonPin);

  if ( buttonState == 0 ) {
    delay(20);
    en++;

    while (en != 0) {
      // ************************ ENCODER read structure ***************************
      // read one of two encoder
      n1 = digitalRead(encoder0PinA1);

      if ( encoder0Pos1 != gradi ) {
        if ((encoder0PinALast1 == LOW) && (n1 == HIGH)  ) {
          if (digitalRead(encoder0PinB1) == LOW) {
            encoder0Pos1--;
          } else {
            encoder0Pos1++;
          }

          Serial.print("Passi: ");
          Serial.println (encoder0Pos1);

        }
        motorrightrun();
      }

      encoder0PinALast1 = n1;

      if ( encoder0Pos1 == gradi || encoder0Pos1 == -gradi) {
        en++;
        encoder1();
      }
      // *************************************************************************
    }
  } 
} 


// L293D run and enable
void motorrightrun() {
  digitalWrite(motorRightEnable_pin, HIGH);
  analogWrite (motorRightPositive, clockwise);
  analogWrite (motorRightNegative, anticlockwise);
}

void encoder1() {
  // disable motor
  digitalWrite(motorRightEnable_pin, LOW);

  if (clockwise != 0 ) {
    anticlockwise = Speed;
    clockwise = 0;
  }
  else {
    anticlockwise = 0;
    clockwise = Speed;
  }
  encoder0Pos1 = 0;
  // when the motor was run forward and back, enable the button
  if (en > 2) {
    en = 0;
    Serial.println("Abilito bottone");
  }
  delay(pausa);
}
