/*
 * Funzione millis e led
 * 
 * Il programma accende il led 13 e stampa sulla seriale
 * il tempo d'attesa prima dello spegnimento.
 * 
 */
#define led 13
unsigned long time=0;
int attesa = 1000;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(led,HIGH);
  Serial.print("Attesa: ");
  Serial.println(attesa);
    
  while(time > attesa){
    time = millis();
  }
  
  digitalWrite(led, LOW);
  Serial.print("Attesa terminata, led spento");
}
