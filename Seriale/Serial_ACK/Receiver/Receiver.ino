/*
   mySerial ACK - Receiver
*/

#define waitTime 1000 //ms
#define ack 255
#define nack 254
#include <SoftwareSerial.h>

const byte numBytes = 32;
byte receivedBytes[numBytes];
byte copy_ndx = 0;
boolean newData = false;

//byte data[5] = {0, 0, 0, 0, 0};

SoftwareSerial mySerial(8, 9);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() {
  Serial.println("Waiting message");

  recvWithStartEndMarkers(0);

  Serial.println("Received.");
  for (byte i = 0; i < 4; i++) {
    Serial.print(receivedBytes[i]);
  }
  Serial.println();
}

//
// Recever and drop the start/end markers
// if transfer OK --> return 1
//
// if time out --> return 0
//
bool recvWithStartEndMarkers(bool timeout) {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = 0x3C; // <
  char endMarker = 0x3E; // >
  char rb;
  unsigned long now = millis();

  while (1) {

    if (  (millis() - now ) < waitTime ) {
      Serial.println("dentro");
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
          //newData = true;
          // if i have not timeout, send the ACK
          if (timeout == 0) {
            mySerial.write(ack);
            Serial.println("Send ACK");
          }
          return 1; // all received
        }
      }
      else if (rb == startMarker) {
        recvInProgress = true;
      }
    }
    else {
      if ( timeout == 1 ) return 0; // time out
      else now = millis(); // go on, no time out
    }
  }
}
