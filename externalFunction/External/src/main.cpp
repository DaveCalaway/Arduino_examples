#include <Arduino.h>
#include "functions.h"

#define ledInternal 13
#define pinDS18 2 

OneWire oneWire(pinDS18);  //Pin number for DS18B20 temperature sensor
DallasTemperature sensors(&oneWire);

// --- SETUP ---
void setup() {
    pinMode(ledInternal, OUTPUT);
    sensors.setResolution(10);       //For DS18B20  Sensor
}

// --- LOOP ---
void loop() {
    blinkBaby(ledInternal,2);

    blinkBaby(ledInternal,10);
}