#include <Arduino.h>
#include <DallasTemperature.h>

#define ledInternal 13
#define pinDS18 2

OneWire oneWire(pinDS18);  //Pin number for DS18B20 temperature sensor
DallasTemperature sensors(&oneWire);

// --- TEMPERATURE ---
float Temperature() {
    sensors.requestTemperatures();             //Fetch temperatures
    float tempC = sensors.getTempCByIndex(0);  //And load variable with correct data
    delay(100);
    return tempC;
}

// --- BLINK BABY ---
void blinkBaby(int secondDelay) {
    int usecond = secondDelay * 1000;

    digitalWrite(ledInternal, HIGH);
    delay(usecond);
    digitalWrite(ledInternal, LOW);
    delay(usecond);
}

// --- SETUP ---
void setup() {
    pinMode(ledInternal, OUTPUT);
    sensors.setResolution(10);  //For DS18B20  Sensor
}

// --- LOOP ---
void loop() {
    blinkBaby(2);

    blinkBaby(10);
}