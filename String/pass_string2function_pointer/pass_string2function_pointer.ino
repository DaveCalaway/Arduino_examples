// PASS AND RETURN STRINGS IN FUNCTIONS

// --- PASS STRING ---
// pass string as a pointer, NOT in this way
// void passString(char passedString[]) {}
void passString(char *passedString) {
  Serial.println(passedString);
}

// --- STRING BACK ---
char *giveMeaStringBack() {
  return "something back";
}

// --- SETUP ---
void setup() {

  char someString[] = "I want to pass this";

  passString(someString);

  char newString[20];
  strncpy(newString, giveMeaStringBack(), sizeof(newString));

  Serial.println(newString);
}


void loop() {
  // put your main code here, to run repeatedly:

}
