/*
  Blink di due led

  Accensione e spegnimanto di un 2 LED utilizzando variabili
  per impostare la velocita' del lampeggio.
  
  Si utilizzeranno due pin d'uscita, con un led e resistenza ciascuno
 */
 
// Dichiarazione variabili

int led1 = 9;
int led2 = 4;
int corta = 100;  // Variabile richiambile nel corso dell'esecuzione
int lunga = 1000;


// Setup: eseguita una volta sola all'accensione della scheda
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);   
}


// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(corta);               
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(corta);               

  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(lunga);               
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(lunga); 
}

/*
 *  Si provi a cambiare lo schema d'accensione e spegnimento
 *  a proprio piacere. 
 *  
 *  Domanda: se volessi utilizzare 3 led, come e dove dovrò
 *  modificare il programma?
 *  
 */
