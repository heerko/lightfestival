// Installeer de HCSR04 library 
// Sketch > Include Libary > Manage Libraries 
// Zoek naar "HCSR04" het is de library gemaakt door Martin Sosic 
// De sensor wordt als volgt aangesloten: 
// Sensor -> Arduino
// GND -> GND
// Echo -> 12
// Trig -> 13
// VCC -> 5V

// laad de NeoPixel library
#include <Adafruit_NeoPixel.h>
// laad de sonar library
#include <HCSR04.h>

// instantieer de ultrasoon sensor
UltraSonicDistanceSensor distanceSensor(13, 12);

// de ledstrip heeft 3 draden. 2 zijn verbonden met 5V en GND, de laatste gaat naar pin 6.
#define PIN        6

// Hoeveel leds zitten er op de strip?
#define NUMPIXELS 30

// Vertel je de Arduino dat je een Neopixel strip hebt aangesloten
// Hiervoor heeft de library drie argumenten nodig:
// - hoeveel pixels, dat hebben we hierboven opgeslagen in de constant NUMPIXELS
// - welke pin, dat is de constante PIN
// - en het laatste geeft de soort neopixels aan. Dit kan je meestal gewoon copy/pasten
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define SMOOTH_ALPHA 0.7

float smoothVal = 0; // global for the smoothing function


void setup() {
  pixels.begin(); // "start" de library
}

void loop() {
  pixels.clear(); // Alle pixels op zwart (uit)
  
  int dist = distanceSensor.measureDistanceCm(); // afstand van de sensor in cm 

  // map de afstand in cm (3-100cm) naar een led op de strip
  // de smooth functie zorgt ervoor dat de ruis een beetje 
  // afgevlakt wordt door een rollend gemiddelde van de
  // laatste paar metingen te maken.
  int led = smooth(map(dist, 3, 100, 0, NUMPIXELS )); 

  // alleen de led corresponderend met de gemeten afstand gaat aan.
  pixels.setPixelColor(led, pixels.Color(255, 0, 255));
  
  pixels.show();  // Stuur de data naar de strip
  delay(500); // Even wachten
}

float smooth(long rawVal) {
  smoothVal = ((float)rawVal * SMOOTH_ALPHA) + (smoothVal * (1 - SMOOTH_ALPHA));
  return smoothVal;
}
