// Primo tocco: led lampeggia ogni mezzo secondo
// Secondo tocco: led lampeggia ogni secondo
// Terzo tocco: led lampeggia ogni secondo e mezzo
// Quarto tocco: led si spegne

const int  BUTTON = 2;    // pin di input a cui è collegato il pulsante
const int LED = 13;       // LED collegato al pin digitale 13

// Variabili globali (tutti interi)
int statoButton     = 0;      // stato del pulsante (inizialmente non premuto)
int lastStatoButton = 0;      // ultimo stato del pulsante (per ora non premuto)
int countButton     = 0;      // Conteggio del bottone

// Avvio dell'applicazione
void setup()
{
  pinMode(LED, OUTPUT);       // imposta il pin digitale come output
  pinMode(BUTTON, INPUT);     // imposta il pin digitale come input
}

// Avvio del loop
void loop()
{

  // Verifico se l'utente ha premuto il bottone
  if(digitalRead(BUTTON))
  {
    // Aspetto 15ms per far alzare il dito all'utente
    delay(15);
    // Cambio l'ultimo stato del bottone
    if(lastStatoButton==0) lastStatoButton=1;
    else lastStatoButton=0;
    // Aumento il count del bottone
    if(countButton<=3) countButton=countButton+1;
    else countButton=0;
  }

  // In base allo stato del bottone scelgo l'azione del led
  switch (countButton)
  {
    // Led lampeggia ogni mezzo secondo
  case 1:
    digitalWrite(LED, HIGH);  // accende il LED
    delay(500);              // aspetta un secondo
    digitalWrite(LED, LOW);   // spegne il LED
    delay(500);              // aspetta un secondo
    break;

    // Led lampeggia ogni secondo
  case 2:
    digitalWrite(LED, HIGH);  // accende il LED
    delay(1000);              // aspetta un secondo
    digitalWrite(LED, LOW);   // spegne il LED
    delay(1000);              // aspettaun secondo
    break;

    // led lampeggia ogni secondo e mezzo
  case 3:
    digitalWrite(LED, HIGH);  // accende il LED
    delay(1500);              // aspetta un secondo
    digitalWrite(LED, LOW);   // spegne il LED
    delay(1500);              // aspetta un secondo
    break;

    // Led si spegne
  case 0:
    delay(15);
    digitalWrite(LED, LOW);
    delay(5000);              // aspetta un secondo
    break;
  }
}
