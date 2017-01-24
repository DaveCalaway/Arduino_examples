/*
 * Esempio base per comprendere l'utlizzo delle neopixel strip con Arduino 5V 16Mz
 */
 
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int aspetto = 500; // delay for half a second

void setup() {
    pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(aspetto); // Delay for a period of time (in milliseconds).
}

// Compitino:
// Inserire un ciclo che ripeta automaticamente led dopo led.
