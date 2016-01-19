/* RGB led
 *  
 *  Imposto tramite un potenziometro la luminosità d'un singolo led RGB alla volta.
 *  Cambio led usando il bottone.
 *  COMMON_CATODE
*/

const int BUTTON = 8;
const int VERDE = 9;
const int BLU = 10;
const int ROSSO = 11;
const int POT = A0;
int statoButton = 0;    
int lastStatoButton = 0;     
int countButton = 0;
int val;


void setup() {
  // imposta il pin IN/OUT
   Serial.begin(9600);
  pinMode(VERDE, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(ROSSO, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(POT, INPUT);

  // inizialmente il led RGB sarà acceso
  digitalWrite(VERDE, LOW);
  digitalWrite(BLU, LOW);
  digitalWrite(ROSSO, LOW);
}


void loop() {
  // Verifico se l'utente ha premuto il bottone  
  if(digitalRead(BUTTON)){  
    // Aspetto 50ms per far alzare il dito all'utente  
    delay(50);  
    // Cambio l'ultimo stato del bottone  
    if(lastStatoButton==0) lastStatoButton=1;  
    else lastStatoButton=0;  
    // Aumento il count del bottone  
    if(countButton<=1) countButton=countButton+1;  
    else countButton=0;  
  }  
  
  Serial.println(countButton);
  val = analogRead(POT); // 0 to 1023
    
  switch (countButton){
    case 0:
      analogWrite(VERDE, 255-(val/4)); // 255 to 0
      break;
    case 1:
      analogWrite(BLU, 255-(val/4));
      break;
    case 2:
      analogWrite(ROSSO, 255-(val/4));
      break;
    }
}
