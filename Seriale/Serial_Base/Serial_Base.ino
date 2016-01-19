/*
 *   Hello World!
 *
 * This is the Hello World! for Arduino. 
 * It shows how to send data to the computer trough the serial connection
 */

void setup()                   
{
  Serial.begin(9600);           // Inposta la seriale a 9600 bps
  // Se Arduino manda 9600 bit per secondo e devi manandare 12 Bytes di dati
  // quanto tempo serve per mandare i dati?

  // Try to change bond rate in the monitor

  Serial.println("Hello World!");   // scrive hello world e ritorna a capo
  

}

void loop()                       
{
  // Provate a mettere i  Serial.printl() qui, magari con un delay()
}



