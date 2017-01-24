/*
  Blink
  Accensione e spegnimento led una volta al secondo.

  Si utilizza il led e la resistenza interna d'Arduino
  sul pin 13.
 */

// Il setup viene fatto solo una volta, all'avvio o dopo un reset
void setup() {
  // Inizializzo il pin 13 come uscita
  pinMode(13, OUTPUT);
}

// Il loop viene eseguito in continuazione 
void loop() {
  digitalWrite(13, HIGH);   // accendi il led
  delay(1000);              // aspetta un secondo
  digitalWrite(13, LOW);    // spegni il led
  delay(1000);              // aspetta un secondo
}

/*
 * Si provi a cambiare l'ordine delle instruzioni nel loop.
 * Se cambio l'ordine, cambia il programma?
 * 
 * Si provi a cambiare il tempo d'attesa - delay - .
 * Qual'è il valore minimo del delay affinchè
 * si riesca ancora a vedere il led spegnersi ed
 * accendersi?
 */
