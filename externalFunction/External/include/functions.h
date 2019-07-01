#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Arduino.h>
#include <DallasTemperature.h>

extern DallasTemperature sensors;

void blinkBaby(byte ledInternal, int secondDelay);

float Temperature();



#endif