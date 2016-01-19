// Esempio 02: accendi il led appena è premuto il pulsante mantenendolo acceso quando si rilascia
// premendo una seconda volta il pulsante spegne il led

#define LED 13                // LED collegato al pin digitale 13
#define BUTTON 7              // pin di input dove è collegato il pulsante
int val = 0;                  // si userà val per conservare lo stato del pin di input
int stato = 0;                // ricorda lo stato in cui si trova il led, stato = 0 led spento, stato = 1 led acceso

void setup() {
  pinMode(LED, OUTPUT);       // imposta il pin digitale come output
  pinMode(BUTTON, INPUT);     // imposta il pin digitale come input
}

void loop() {
  val = digitalRead(BUTTON);  // legge il valore dell'input e lo conserva

  // controlla che l'input sia HIGH (pulsante premuto)
  // e cambia lo stato del led
  if (val == HIGH) {
    stato = 1 - stato;
    // stato = !stato;
  } 

  if (stato == 1) {
    digitalWrite(LED, HIGH);   // accende il led
  }
  else {
    digitalWrite(LED, LOW);    //spegne il led
  }
}

/*
 * Perchè alcune volte funziona ed altre no?
 * Arduino è velocissimo a controllare i cicli, lo stato del led, 
 * ed alcune volte può risultare impossibile verificare correttamente
 * lo stato del bottone.
 * 
 * Abbiamo bisogno d'una variabile che si ricordi lo stato precedente
 * del led.
 */
