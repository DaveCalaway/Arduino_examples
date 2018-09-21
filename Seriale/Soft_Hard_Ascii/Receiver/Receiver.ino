// Receive 
// That sketch receive through Software Serial an ascii with start- and end-markers, 
// and prints it over the Hardware Serial.


#include <SoftwareSerial.h>

const byte numChars = 32;
char receivedChars[numChars];
byte copy_ndx = 0;

boolean newData = false;

SoftwareSerial mySerial(10, 11); // RX, TX Software Serial

//============

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); // Software Serial
  Serial.println("Ready");
  Serial.println();
}

//============

void loop() {
  recvWithStartEndMarkers();
  if (newData == true) {
    Serial.print("Ho ricevuto: ");
    for (byte i = 0; i < copy_ndx; i++) {
      Serial.print( receivedChars[i] );
    }
    Serial.println();
    newData = false;
  }
}

//============

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (mySerial.available() > 0 && newData == false) {
    rc = mySerial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        copy_ndx = ndx;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

