/*  strcmp example

   DaveCalaway
*/

#define case1
//#define case2

#ifdef case1
const char ready[9] = {"READY_200"};  // defined array size, NO auto teminated with \0
#endif
#ifdef case2
const char ready[] = {"READY_200"};  // no array size, it will be AUTO teminated with \0
#endif



void setup() {
  Serial.begin(9600);
}

void loop() {
  char buffer[20];
  byte i = 0;

  while (Serial.available() > 0) {  // have i received something?
    buffer[i] = Serial.read();
    i++;
  }
  buffer[i] = '\0';  // ADD NULL TERMINATOR

  char msg[i+1];
  strcpy(msg, buffer);

  Serial.println(msg);
  delay(500);

  if (strcmp(msg, ready) == 0) {  // have i received "READY_200"?
    Serial.println("ok");
  }

}


/*
   Case1 doesn't works because strcpy search until it found "\0" and because all C string ( not String ) works with "\0".
   Case2 case works because ready is AUTO terminated with "\0".
*/
