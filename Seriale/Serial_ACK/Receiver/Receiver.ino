// Receive
// That sketch receive through Software Serial same bytes with start- and end-markers,
// send back an ack and prints it over the Hardware Serial.


#include <SoftwareSerial.h>
#define ack 255

const byte numBytes = 32;
byte receivedBytes[numBytes];
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
    Serial.print("I received: ");
    for (byte i = 0; i < copy_ndx; i++) {
      Serial.print( receivedBytes[i] );
    }
    Serial.println();
    newData = false;

    Serial.println("Send ACK.");
    sendACK();
  }
}

//
//============
//
void sendACK() {
  mySerial.write(0x3C);
  mySerial.write(ack);
  mySerial.write(0x3E);
}


//
//============
//
void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  byte startMarker = 0x3C; // <
  byte endMarker = 0x3E; // >
  byte rb;

  while (mySerial.available() > 0 && newData == false) {
    rb = mySerial.read();

    if (recvInProgress == true) {
      if (rb != endMarker) {
        receivedBytes[ndx] = rb;
        ndx++;
        if (ndx >= numBytes) {
          ndx = numBytes - 1;
        }
      }
      else {
        receivedBytes[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        copy_ndx = ndx;
        ndx = 0;
        newData = true;
      }
    }
    else if (rb == startMarker) {
      recvInProgress = true;
    }
  }
  // the buffer is empty but you have not received the endMarker
  if (newData == false) {
    // clean the receiver array
    for (byte i = 0; i < ndx; i++) {
      receivedBytes[ndx] = 0;
    }
  }// That cause the resend
}
