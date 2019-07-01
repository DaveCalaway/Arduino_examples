#include <functions.h>

// --- BLINK BABY ---
void blinkBaby(byte ledInternal, int secondDelay) {
    int usecond = secondDelay * 1000;

    digitalWrite(ledInternal, HIGH);
    delay(usecond);
    digitalWrite(ledInternal, LOW);
    delay(usecond);
}

// --- TEMPERATURE ---
float Temperature() {
    sensors.requestTemperatures();             //Fetch temperatures
    float tempC = sensors.getTempCByIndex(0);  //And load variable with correct data
    delay(100);
    return tempC;
}