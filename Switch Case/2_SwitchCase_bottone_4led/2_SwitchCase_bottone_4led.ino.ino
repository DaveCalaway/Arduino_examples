// Esempio 9: conta quante volte il pulsante viene premuto, per un ciclo di 4 pressioni,
// ad ogni pressione del pulsante si accende un led per volta
// alla quinta pressione il primo led lampeggia per 10 volte.
// Il controllo del numero di volte in cui il pulsante viene premuto viene fatto con l'istruzione "case"

#define BUTTON 2                                   // pin di input a cui è collegato il pulsante
#define LED1 13                                    // LED collegato al pin digitale 13
#define LED2 12                                    // LED collegato al pin digitale 12
#define LED3 11                                    // LED collegato al pin digitale 11
#define LED4 10                                    // LED collegato al pin digitale 10

// Variabili
int ContatorePulsantePremuto = 0;                   // conta il numero di volte che il pulsante è premuto buttonPushCounter 
int StatoPulsante = 0;                              // stato corrente del pulsante
int StatoPulsantePrecedente = 0;                    // stato precedente del pulsante

void setup() {
  pinMode(BUTTON, INPUT);                           // imposta il pin digitale come output
  pinMode(LED1, OUTPUT);                            // imposta il pin digitale come input
  pinMode(LED2, OUTPUT);                            // imposta il pin digitale come input
  pinMode(LED3, OUTPUT);                            // imposta il pin digitale come input
  pinMode(LED4, OUTPUT);                            // imposta il pin digitale come input
  Serial.begin(9600);                               // apre la porta seriale e la inizzializza a 9600 bps
}

void loop() {
  StatoPulsante = digitalRead(BUTTON);              // legge il valore dell'input e lo conserva

  if (StatoPulsante != StatoPulsantePrecedente) {   // compara lo stato del pulsante attuale con il precedente
    if (StatoPulsante == HIGH) {                    // se lo stato è cambiato incrementa il contatore
      // se lo stato corrente è alto, il pulsante è passato da off a on
      ContatorePulsantePremuto++;

      switch (ContatorePulsantePremuto) {
      case 1:  // controlla se il pulsante è stato premuto una volta
        Serial.println("on");                                // stampa sulla console "on"
        Serial.print("numero di volte tasto premuto:  ");    // stampa sulla console "numero di volte tasto premuto:"
        Serial.println(ContatorePulsantePremuto, DEC);       // stampa il numero di volte che il pulsante è stato premuto
        digitalWrite(LED1, HIGH);                                 // accende il LED  
        Serial.println("off");                               // stampa sulla console "off"
        break;
      case 2:  // controlla se il pulsante è stato premuto due volte
        Serial.println("on");                                // stampa sulla console "on"
        Serial.print("numero di volte tasto premuto:  ");    // stampa sulla console "numero di volte tasto premuto:"
        Serial.println(ContatorePulsantePremuto, DEC);       // stampa il numero di volte che il pulsante è stato premuto
        digitalWrite(LED1, LOW);                                 // accende il LED  
        digitalWrite(LED2, HIGH);                                 // accende il LED  
        Serial.println("off");                               // stampa sulla console "off"
        break;
      case 3:  // controlla se il pulsante è stato premuto tre volte
        Serial.println("on");                                // stampa sulla console "on"
        Serial.print("numero di volte tasto premuto:  ");    // stampa sulla console "numero di volte tasto premuto:"
        Serial.println(ContatorePulsantePremuto, DEC);       // stampa il numero di volte che il pulsante è stato premuto
        digitalWrite(LED2, LOW);                                 // accende il LED  
        digitalWrite(LED3, HIGH);                                 // accende il LED  
        Serial.println("off");                               // stampa sulla console "off"
        break;
      case 4:  // controlla se il pulsante è stato premuto quattro volte
        Serial.println("on");                                // stampa sulla console "on"
        Serial.print("numero di volte tasto premuto:  ");    // stampa sulla console "numero di volte tasto premuto:"
        Serial.println(ContatorePulsantePremuto, DEC);       // stampa il numero di volte che il pulsante è stato premuto
        digitalWrite(LED3, LOW);                                 // accende il LED  
        digitalWrite(LED4, HIGH);                                 // accende il LED  
        Serial.println("off");                               // stampa sulla console "off"
        break;
      }
    } 
  }

  // salva lo stato corrente nella variabile che indica lo stato precedente per il loop successivo 
  StatoPulsantePrecedente = StatoPulsante;

  // controlla se il pulsante è stato premuto quattro volte se vero indica che è finito il ciclo
  // il led lampeggia 2 volte per 50 millisecondi
  // vengono inizializzate nuovamente le variabili
  // si riavvia il ciclo

  if (ContatorePulsantePremuto > 4) {
    Serial.println("fine ciclo");
    digitalWrite(LED4, LOW);                                 // accende il LED  
    delay(50); 
    for (int x=0; x<10; x++) {                                 // lampeggia per 10 volte
      digitalWrite(LED1, HIGH);                                 // accende il LED  
      delay(50);                                               // aspetta 50 millisecondi  
      digitalWrite(LED1, LOW);                                  // spegne il LED  
      delay(50);                                               // aspetta 50 millisecondi
    }
    // inizializzazione delle variabili
    ContatorePulsantePremuto = 0;
    StatoPulsante = 0;
    StatoPulsantePrecedente = 0;
    Serial.println("mi riavvio");                            // stampa sulla console "mi riavvio"
  }
}
