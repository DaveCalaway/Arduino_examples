// Sender
// That sketch one array of bytes to another Arduino by serial, wait 
// the ACK or retransmits.

#include <SoftwareSerial.h>
#define ack 255

byte test [] = {1, 2, 3, 4, 5, 6, 7};

const byte numBytes = 32;
byte receivedBytes[numBytes];
byte copy_ndx = 0;

boolean newData = false;

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  bool check = 0;

  while (check == 0) {
    mySerial.write(0x3C);
    for (byte i = 0; i < 7; i++) {
      mySerial.write(test[i]);
    }
    mySerial.write(0x3E);
    Serial.println("Sended.");

    check = waitACK();
    if (check == 0) Serial.println("no ACK, resend");
  }

  Serial.println("ACK received");
  delay(3000);
}

//
// ================================
// Return 0 --> no ACK, resend
// Return 1 --> ok ACK
bool waitACK() {

  // waiting the Receiver can send the ACK
  delay(250);

  recvWithStartEndMarkers();

  if (newData == true && receivedBytes[0] == ack) {
    newData = false;
    return 1;
  }
  else {
    newData = false;
    return 0;
  }
}

//
// ================================
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
}


