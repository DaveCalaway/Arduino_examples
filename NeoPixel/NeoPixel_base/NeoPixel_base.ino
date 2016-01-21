#include <Adafruit_NeoPixel.h>

// Con quale pin d'Arduino controlli la striscia NeoPixel?
#define PIN            6

// Quanti led ha la tua striscia NeoPixel?
#define NUMPIXELS      10

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // ritardo di mezzo secondo

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){
    // pixels.setPixelColor(n° pixel,colore) 
    // pixels.Color(R,G,B) da 0 to 255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

    pixels.show(); // Aggiorna la striscia

    delay(delayval); 

  }
}
