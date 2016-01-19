// Esempio 01: accendi il led appena è premuto il pulsante  
// 10K per pull-down
  
#define LED 13                // LED collegato al pin digitale 13  
#define BUTTON 7              // pin di input dove è collegato il pulsante  
int  val = 0;                 // si userà val per conservare lo stato del pin di input  
  
void setup() {  
  pinMode(LED, OUTPUT);       // imposta il pin digitale come output  
  pinMode(BUTTON, INPUT);     // imposta il pin digitale come input  
}  
  
void loop() {  
  val = digitalRead(BUTTON);  // legge il valore dell'input e lo conserva  
  
  // controlla che l'input sia HIGH (pulsante premuto)  
  if (val == HIGH) {  
    digitalWrite(LED, HIGH);  //accende il led  
  }  
  else {  
    digitalWrite(LED, LOW);   //spegne il led  
  }  
}
