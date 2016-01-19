/*
 * Funzione millis e led
 * 
 * Il programma accende il led 13 e stampa sulla seriale
 * il tempo d'attesa prima dello spegnimento.
 * 
 */
#define led 13
unsigned long time = 0;
int tON = 1000;
unsigned long val = 0;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.print("Attesa: ");
  Serial.println(tON);
}

void loop(){
  digitalWrite(led,HIGH);
  
  val = millis() + tON;
  
  while(time < val){
    time = millis();
  }
  
  digitalWrite(led, LOW);
  delay(1000);
}

/*
 * Domanda: perchè nelle variabili tON è un intero?
 */
