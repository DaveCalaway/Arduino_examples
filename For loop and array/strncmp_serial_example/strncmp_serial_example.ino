/*  strncmp example
  Check if the Buffer string star with a specific string, in this case sync.

   DaveCalaway
*/

const char sync[] = {"SYNC"}; // no array size, it will be AUTO teminated with \0

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

  char msg[i + 1];  // buffer size + \0
  strcpy(msg, buffer);

  if (strncmp(msg, sync, strlen(sync)) == 0) { // have i received "SYNC,X,Y,END"?
    Serial.println("SYNC");
    char *point;
    byte p = 0;

    point = strtok(msg, ",");

    while (point != NULL && p < 3) {  // extract x and y position next SYNC
      Serial.println(point);

      point = strtok(NULL, ",");  // go to the next ","
    }
  }
}
