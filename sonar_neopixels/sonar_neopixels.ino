// Installeer de HCSR04 library 
// Sketch > Include Libary > Manage Libraries 
// Zoek naar "HCSR04" het is de library gemaakt door Martin Sosic 
// De sensor wordt alsvolgt aangesloten: 
// Sensor -> Arduino
// GND -> GND
// Echo -> 12
// Trig -> 13
// VCC -> 5V

#include <Adafruit_NeoPixel.h>
#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(13, 12);

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6

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
  int dist = distanceSensor.measureDistanceCm(); // afstand van de sensor in cm 
  int led = map(dist, 3, 100, 0, NUMPIXELS ); // map de afstand in cm (3-100cm) naar een led op de strip
  pixels.setPixelColor(led, pixels.Color(255, 0, 255));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop
}
