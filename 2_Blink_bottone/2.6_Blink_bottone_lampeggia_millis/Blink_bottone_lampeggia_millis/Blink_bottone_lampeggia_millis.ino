// Esempio 06: led lampeggia se premo il pulsante
// premendo una seconda volta il pulsante si spegne il led in qualsiasi momento

#define LED 13                // LED collegato al pin digitale 13
#define BUTTON 7              // pin di input dove è collegato il pulsante
int val = 0;                  // si userà val per conservare lo stato del pin di input
int vecchio_val = 0;          // si userà vecchio_val per conservare lo stato del pin di input al passo precedente
int stato = 0;                // ricorda lo stato in cui si trova il led, stato = 0 led spento, stato = 1 led acceso
unsigned long previousMillis = 0;

void setup() {
  pinMode(LED, OUTPUT);       // imposta il pin digitale come output
  pinMode(BUTTON, INPUT);     // imposta il pin digitale come input
  Serial.begin(9600);  
}

void loop() {
  
  val = digitalRead(BUTTON);  // legge il valore dell'input e lo conserva
  unsigned long currentMillis = millis();
  
  // controlla se è accaduto qualcosa
  if ((val == HIGH) && (vecchio_val == LOW)){
    Serial.println("bottone premuto");
    
    Serial.println(currentMillis);
    previousMillis = currentMillis+15;
    while(currentMillis < previousMillis ){
      currentMillis = millis();
    }
     Serial.println(currentMillis);
      stato = 1 - stato;
    //delay(15);                // attesa di 15 millisecondi
    
  } 

  vecchio_val = val;          // ricordiamo il valore precedente di val

    if (stato == 1) {
      
    Serial.println("accendo led");
    digitalWrite(LED, HIGH);  // accende il LED
    //delay(1000);              // aspetta un secondo
    
    unsigned long currentMillis = millis();
    previousMillis = currentMillis+1000;
    
    while(currentMillis < previousMillis){
      currentMillis = millis();
      val = digitalRead(BUTTON);
      if(val != vecchio_val){
        digitalWrite(LED, LOW); 
        Serial.println("interrompi");
        break;
      }
    }
    Serial.println("spengo led");
    digitalWrite(LED, LOW);   // spegne il LED
    
    //delay(1000);              // aspetta un secondo
    currentMillis = millis();
    previousMillis = currentMillis+1000;
    while(currentMillis < previousMillis){
      currentMillis = millis();
      val = digitalRead(BUTTON);
      if(val != vecchio_val){
        digitalWrite(LED, LOW); 
        Serial.println("interrompi");
        break;
      }
    }
  }
} //loop
