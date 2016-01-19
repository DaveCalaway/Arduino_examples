// Esempio 03: antirimbalzo
// accendi il led appena è premuto il pulsante mantenendolo acceso quando si rilascia
// premendo una seconda volta il pulsante spegne il led

#define LED 13                // LED collegato al pin digitale 13
#define BUTTON 7              // pin di input dove è collegato il pulsante
int val = 0;                  // si userà val per conservare lo stato del pin di input
int vecchio_val = 0;          // si userà vecchio_val per conservare lo stato del pin di input al passo precedente
int stato = 0;                // ricorda lo stato in cui si trova il led, stato = 0 led spento, stato = 1 led acceso

void setup() {
  pinMode(LED, OUTPUT);       // imposta il pin digitale come output
  pinMode(BUTTON, INPUT);     // imposta il pin digitale come input
}

void loop() {
  val = digitalRead(BUTTON);  // legge il valore dell'input e lo conserva

  // controlla se è accaduto qualcosa
  if ((val == HIGH) && (vecchio_val == LOW)){
    stato = 1 - stato;
  } 

  vecchio_val = val;            // ricordiamo il valore precedente di val

  if (stato == 1) {
    digitalWrite(LED, HIGH);   // accende il led
  }
  else {
    digitalWrite(LED, LOW);    //spegne il led
  }
}

/*
 * Il problema della difficoltà nel capire lo stato del bottone si
 * ripresenta se premiamo troppo velocemente il bottone.
 * Questo è dovuto alla fisica non ideale del fronte di salita e 
 * discesa dello stato del bottone ( on - off ).
 * 
 */
