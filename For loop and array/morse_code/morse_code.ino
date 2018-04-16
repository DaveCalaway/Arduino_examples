/*
   Morse code
   The sketch print and command a led according to the morse code.
   https://goo.gl/zFsDML

   DaveCalaway
*/

int led = 13;

// array of single char for morse code
char morse_code[15] = {'-', '.', '.', '-', '.', ' ', '.', '.', ' ', '.', '-', ' ', '-', '-', '-'}; // ciao

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // extracts the char from the array one by one
  for (int i = 0; i < 15; i++) {
    int characters = morse_code[i];
    Serial.println(characters);

    // analyze the char
    if (characters == '-') {
      digitalWrite(led, 1);
      delay(1000);
      digitalWrite(led, 0);
    }

    if (characters == '.') {
      digitalWrite(led, 1);
      delay(250);
      digitalWrite(led, 0);
    }

    else {
      delay(1000);
    }

    delay(100);
  }

  Serial.println("End of communication.");
  delay(1000);
}

// Perchè non stampa bene?
// cosa stampa? Ascii code!
//conversione int to char della variabile "characters"
