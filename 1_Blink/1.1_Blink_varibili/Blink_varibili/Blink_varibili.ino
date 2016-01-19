/*
  Blink con variabili

  Accensione e spegnimanto di un LED utilizzando variabili
  per impostare la velocita' del lampeggio.
  
  Utilizza il pin 13, con già il led e la resistenza interne d'arduino.
  
 */
 
// Dichiarazione variabili

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int breve = 100;  // Variabile richiambile nel corso dell'esecuzione
int lunga = 1000;


// Setup: eseguita una volta sola all'accensione della scheda
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}


// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(corta);               
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(corta);               

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(lunga);               
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(lunga); 
}

/*
 *  Si provi a cambiare i valori della variabile conta e lunga.
 *  
 *  Se utilizzo una resistenza di valore maggiore, cosa noto?
 */
