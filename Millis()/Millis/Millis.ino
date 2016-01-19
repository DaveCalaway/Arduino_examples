/*
 * Funzione millis.
 * Millis è un contatore interno ad Arduino che tiene traccia,
 * come un orologio, del tempo trascorso.
 * 
 * Il programma stampa sulla seriale il tempo strascorso in millis
 * ogni secondo.
 */
unsigned long time;

void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.print("Time: ");
  time = millis();
  //prints time since program started
  Serial.println(time);
  // wait a second so as not to send massive amounts of data
  delay(1000);
}
