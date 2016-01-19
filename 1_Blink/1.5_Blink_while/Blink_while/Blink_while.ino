#include <SoftwareSerial.h>

/*
  Blink v3
 Accensione e spegnimanto di un LED utilizzando un ciclo
 iterativo while per comandare il lampeggio.
 
 */

int led   = 13;
int breve = 200;  
int lunga = 1000;


// /////////////////
// Setup: eseguita una volta sola all'accensione della scheda
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  Serial.begin(9600);
}

// ///////////////
// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  int iterator = 0; // Defniamo un variabile per controllare un ciclo iterativo
  while (iterator < 10) {
    rapido(); // accende e spegne rapidamente il LED
    iterator = iterator + 1 ; // incrementa l'iteratore
    
    Serial.print("rapido:");
    Serial.println(iterator);
    // iterator++ ; // equivalente
  }
  lento();  // accende e spegne lentamente il LED
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


/* Domande
 *  
 *  1. Creare una funziona lampeggia() che accetti come parametro
 *  il nuomero di ripetizioni da eseguire.
 *  
 */
