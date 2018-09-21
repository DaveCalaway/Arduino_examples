/*
   mySerial ACK - Sender
*/

#define waitTime 1000 //ms
#define ack 255
#define nack 254
#include <SoftwareSerial.h>

const byte numBytes = 32;
byte receivedBytes[numBytes];
byte copy_ndx = 0;
boolean newData = false;

byte data[5] = {0, 1, 2, 3, 4};

SoftwareSerial mySerial(8, 9);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  bool check = 0;

  while (check == 0) {
    Serial.println("Sending data");
    mySerial.write("<");
    for (byte i = 0; i < 5; i++) {
      mySerial.write(data[i]);
    }
    mySerial.write(">");

    // Waiting ACK
    Serial.println("Waiting ACK");
    check = waitACK();
    if (check == 0) {
      Serial.println("No ACK");
    }
  }

  Serial.println("Sent.");
  delay(5000);
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
  //bool timeOut = 0;
  unsigned long now = millis();

  while (1) {

    if (  (millis() - now ) < waitTime ) {
      //Serial.println("dentro");
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
          if (timeout == 0) mySerial.write(ack);
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

//
// waiting ACK
// return 0 --> time out or error
// return 1 --> transfer OK
//
bool waitACK() {
  bool check = 0;
  unsigned long now = millis();

  while (mySerial.available() == 0) { // waiting ACK
    //Serial.println("dentro");
    if ((millis() - now ) < waitTime){
      Serial.println("time out");
      return 0; // time out
    }
  }
  Serial.println("ricevuto");
  check = recvWithStartEndMarkers(0); // with timeout

  if (check == 1) { // all arrived
    return 1;
  }
  else return 0; // error
}

