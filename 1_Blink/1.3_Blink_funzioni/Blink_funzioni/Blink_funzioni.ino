
// ////////////
// Commento iniziale
/*
  Blink v2
 
 Accensione e spegnimanto di un LED utilizzando funzioni
 per comandare il lampeggio.
 
 This example code is in the public domain.
 */
// //////////////
// Dichiarazione variabili

int led = 13; // LED onboard sulla scheda
int breve = 200;  // Variabile richiambile nel corso dell'esecuzione
int lunga = 1000;

// /////////////////
// Setup: eseguita una volta sola all'accensione della scheda
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// ///////////////
// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  rapido(); // accende e spegne rapidamente il LED
  rapido(); // accende e spegne rapidamente il LED
  lento();  // accende e spegne lentamente il LED
}

// ///////////////
// Funzioni create dall'utente:

void rapido() {
  // Accende e spegne rapidamente il LED

  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);    // turn the LED on (HIGH is the voltage level)
  delay(breve);               // wait for a second
  digitalWrite(led, LOW);     // turn the LED off by making the voltage LOW
  delay(breve);               // wait for a second
}

void lento() {  
  // Accende e spegne lentamente il LED

  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(led, HIGH);    // turn the LED on (HIGH is the voltage level)
  delay(lunga);               // wait for a second
  digitalWrite(led, LOW);     // turn the LED off by making the voltage LOW
  delay(lunga); 
}

/* Domande:
 *  1. I valori delle variabili led, breve, lunga cambiano durante
 *  l'esecuzione del programma? Sono variabili?
 *  
 *  2. Le dichiarazioni delle variabili breve e lunga possono essere
 *  accorpate nelle rispettive funzioni?
 */
