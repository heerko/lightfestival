// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6
#define POT        A0

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 44

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  int pot = analogRead(A0);
  int led = map(pot, 0, 1023, 0, NUMPIXELS );

  //  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
  // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
  // Here we're using a moderately bright green color:
  pixels.setPixelColor(led, pixels.Color(255, 0, 255));

  pixels.show();   // Send the updated pixel colors to the hardware.

  delay(DELAYVAL); // Pause before next pass through loop

  pixels.setPixelColor(led, pixels.Color(0, 0, 0));
  //  }
}
