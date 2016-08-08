/* Dave Calaway 22/06/2016 - V0.3
   GIT: https://goo.gl/O5A4XS
   Control DC motor with encoder and L293D. The sketch print the angles in real time.
   No library needed.
*/

//---------------------------- IMPOSTAZIONI ---------------------------------
// numero di gradi da fare, avanti ed indietro. 850 quasi 360°
#define gradi 850
// attesa prima del ritorno a 0, 1000 = 1sec
#define pausa 1000
//---------------------------------------------------------------------------

// the motor will start at clockwise
int clockwise = 50;
int anticlockwise = 0;

/* L293D: motor terminals and enable pin */

int motorRightPositive = 5;
int motorRightNegative = 6;
int motorRightEnable_pin = 12;

/*Encoder connect pins */

int encoder0PinA1 = 7;
int encoder0PinB1 = 8;
int encoder0Pos1 = 0;
int encoder0PinALast1 = LOW;
int n1 = LOW;


void setup() {
  pinMode (encoder0PinA1, INPUT);
  pinMode (encoder0PinB1, INPUT);
  Serial.begin (115200);

  pinMode (motorRightPositive, OUTPUT);
  pinMode (motorRightNegative , OUTPUT);
  pinMode(motorRightEnable_pin, OUTPUT);
}

void loop() {
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
    encoder1();
  }
// *************************************************************************
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
    anticlockwise = 50;
    clockwise = 0;
  }
  else {
    anticlockwise = 0;
    clockwise = 50;
  }
  encoder0Pos1 = 0;
  Serial.println("cambio!");
  delay(pausa);
}
