  /* 
 Uso di un led RGB
  COMMON_ANODE, 255 = OFF
 Spegnimento graduale del LED Verde
*/

// pin a cui collegare i piedini del LED RGB
const int ROSSO = 11;
const int BLU = 9;
const int VERDE = 10;

// tempo di transizione colore
const int delayTime = 20;

void setup() {
  // imposta il pin digitale come output
  pinMode(VERDE, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(ROSSO, OUTPUT);


  // si impostano ad HIGH i pin VERDE, BLU, ROSSO
  // inizialmente il led RGB sarà spento, perchè COMMON_ANODE
  digitalWrite(VERDE, HIGH);
  digitalWrite(BLU, HIGH);
  digitalWrite(ROSSO, HIGH);
}

// definizione di variabili globali
int ValVerde;

void loop() {
  // spegnimento graduale del verde

  // coordinate RGB del verde: 0, 255, 0

  ValVerde = 255;

  for( int i = 0 ; i < 255 ; i += 1 ){

    ValVerde -= 1;

    /* ad ogni ciclio la differenza
     255 - ValVerde AUMENTA
     provocando un graduale spegnimento del verde
     */

    analogWrite( VERDE, 255 - ValVerde );

    // attesa di 20 ms per percepire il colore
    delay( delayTime );
  }
}

/*
 * Esercizio 1:
 * spegnere il led rosso.
 * 
 * Esercizio 2:
 * spegnere il led blu.
 * 
 */
