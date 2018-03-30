/*
  Read an analog signal ( potentiometer ) and smooth the output ( noise ) 
  with Exponential moving average ( low pass ) https://goo.gl/fkpxH9 . 
  The example plot 2 value, 
      "sensorValue" without filter
      "EMA_S" with filter

  DaveCalaway
*/

#define sensorPin  A0    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
float EMA_a = 0.1;      //initialization of EMA alpha
int EMA_S = 0;          //initialization of EMA S

void setup() {
  Serial.begin(115200);
  //EMA_S = analogRead(sensorPin);  //set EMA S for t=1
}

void loop() {
  sensorValue = analogRead(sensorPin);                //read the sensor value using ADC
  EMA_S = (EMA_a * sensorValue) + ((1 - EMA_a) * EMA_S); //run the EMA
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(EMA_S);                              //print digital value to serial
  delay(10);                                          //10ms delay
}

/*
   What happen if you uncomment EMA_S ?
   What happen if you modify the delay?
   What happen if you modify the EMA_a? remember  1<EMA_a<0
*/

