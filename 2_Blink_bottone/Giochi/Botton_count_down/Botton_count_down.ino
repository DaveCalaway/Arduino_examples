/*
 *  Contatore di input

    Il programma rileva la pressione del bottone e
    riduce un contatore ad ogni pressione.
 */

int switchPin = 7;              // switch is connected to pin 2
int val;                        // variable for reading the pin status
int buttonState;                // variable to hold the last button state
int buttonPresses = 10;         // Counter for the button

void setup() {
  pinMode(switchPin, INPUT);    // Set the switch pin as input

  Serial.begin(9600);           // Set up serial communication at 9600bps
  buttonState = digitalRead(switchPin);   // read the initial state
  Serial.println("Don not press the button! :P ");
}


void loop(){
  val = digitalRead(switchPin);      // read input value and store it in val
  delay(100);                        // Debounce
  if ((val != buttonState) && (val == HIGH)) {     // check if the button is pressed
    buttonPresses = buttonPressed - 1;
    //buttonPresses-- ;
    Serial.print("Press it an other ");
    Serial.print(buttonPresses);
    Serial.println(" times.");
  }
  if (buttonPresses == 0) {
    Serial.println("----- >  ExplOdE! <------");
  }
  buttonState = val;                 // save the new state in our variable
}

/*
 * Esercizio:
 * far partire il conteggio da 0 ed incrementare il contatore, 
 * far esplodere a 7 pressioni.
 * 
 */
