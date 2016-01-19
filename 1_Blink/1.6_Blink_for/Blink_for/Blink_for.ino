/*
  Blink v4
 Accensione e spegnimanto di un LED utilizzando un ciclo
 iterativo for per comandare il lampeggio.
 
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int breve = 200;  // Variabile richiambile nel corso dell'esecuzione
int lunga = 1000;

// Setup: eseguita una volta sola all'accensione della scheda
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  for (int i = 0, i <10, i++) { 
// (Definizione iteratore, condizione di verifica, gestione dell'iteratore)
// Operatore ternario (3 elementi)
      rapido(); // accende e spegne rapidamente il LED
  }
  
  lento();  // accende e spegne lentamente il LED
  // Domanda: dobbiamo preoccuparci dell'iteratore?
}

// Funzioni create dall'utente:

void rapido() {
  // Accende e spegne rapidamente il LED

  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(breve);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(breve);               // wait for a second
}

void lento() {  
  // Accende e spegne lentamente il LED

  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(lunga);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(lunga); 
}


