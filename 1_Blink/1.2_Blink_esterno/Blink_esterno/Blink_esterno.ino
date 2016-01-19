/*
  Blink esterno

  Accensione e spegnimanto di un LED, sulla breadboard, utilizzando variabili
  per impostare la velocita' del lampeggio.
  
  Si utilizzi il pin 8, con resistenza e led esterno.
  
 */
 
// Dichiarazione variabili
int led = 8;
int breve = 100;  
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
