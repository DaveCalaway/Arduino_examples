/* Combinazione leds/bottoni

   Ogni bottone accende un led, se premo entrami i bottoni accendo il terzo led.

   Seguendo lo schema elettrico proposto, inserire i dati mancanti.
*/

// Variabili
int button1 = ;
int button2 = ;
int led1 = ;
int led2 = ;
int led3 = ;
int bottone_premuto = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Funzione di controllo bottoni
  stato_bottoni();

  if (bottone_premuto == 1) {
    digitalWrite(led1, HIGH);
  }

  if (bottone_premuto == 2) {
    digitalWrite(led2, HIGH);
  }

  if (bottone_premuto == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }

  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}


void stato_bottoni() {

  if (digitalRead(button1) == HIGH && digitalRead(button1) == LOW) {
    bottone_premuto = 1;
  }

  if (digitalRead(button1) == LOW && digitalRead(button2) == HIGH) {
    bottone_premuto = 2;
  }

  if (digitalRead(button1) == HIGH && digitalRead(button2) == HIGH) {
    bottone_premuto = 3;
  }

  else {
    bottone_premuto = 0;
  }

}


/*
 * Domanda:
 * In quale caso si verifica un problema? come lo risolvo?
 */

