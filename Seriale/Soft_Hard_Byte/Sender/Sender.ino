// Sender
// That sketch send two array of int to another Arduino by serial.

int test [] = {1, 2, 3, 4, 5, 6, 7};
int test2 [] = {7, 6, 5, 4, 3, 2, 1};

void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.print("<");
  for (byte i = 0; i < 7; i++) {
    Serial.print(test[i]);
  }
  Serial.println(">");

  delay(500);

  Serial.print("<");
  for (byte i = 0; i < 7; i++) {
    Serial.print(test2[i]);
  }
  Serial.println(">");

}
