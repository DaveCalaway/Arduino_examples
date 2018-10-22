/*
   RGB base

   Accendo e spengo i singoli leds. In questo esempio si usa un
   RBG led di tipo Catodo Comune.
*/

// Dichiaro le variabili
int ledVerde = 11;
int ledBlu = 10;
int ledRosso = 9;
int tempo = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledVerde, OUTPUT);
  pinMode(ledBlu, OUTPUT);
  pinMode(ledRosso, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledVerde, HIGH);
  delay(tempo);
  digitalWrite(ledVerde, LOW);
  delay(tempo);

  digitalWrite(ledBlu, HIGH);
  delay(tempo);
  digitalWrite(ledBlu, LOW);
  delay(tempo);

  digitalWrite(ledRosso, HIGH);
  delay(tempo);
  digitalWrite(ledRosso, LOW);
  delay(tempo);
}

/*
    Esercizo 1: accendo in sequenza il ledRosso, ledVerde e ledBlu
    Esercizo 2: creo una combinazione a piacere mixando i colori
*/
