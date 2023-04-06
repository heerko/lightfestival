/*
 * In dit voorbeeld worden de pixels om de beurt groen
 * dvm een loop.
 * 
 * Oefeningen: 
 * - Hoe verander je de kleur?
 * - Hoe verander je de snelheid waarmee het lichtje over de strip beweegt?
 * - Hoe kan je het lichtje maar tot halverwege de strip laten gaan?
 */
// laad de NeoPixel library
#include <Adafruit_NeoPixel.h>

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

int pixelCnt = 0; // dit is een teller waarin we gaan bijhouden welke pixel een kleur moet krijgen

void setup() {
  pixels.begin(); // "start" de library
}

void loop() {
  // We beginnen met alle pixels op zwart.
  pixels.clear();
  // geef de huidige (waarde van pixelCnt) pixel een kleur
  pixels.setPixelColor(pixelCnt, pixels.Color(0, 100, 50));
  // tel 1 op bij pixelCnt, zodat de volgende loop we de volgende pixel gaan gebruiken
  pixelCnt = pixelCnt + 1;
  // aan het einde van de strip beginnen we opnieuw
  if(pixelCnt > NUMPIXELS) {
    pixelCnt = 0;
  }
  // pixels.show(); moet altijd, de data wordt dan pas naar de strip verzonden. 
  pixels.show();
  // even wachten anders gaat het te snel.
  delay(50);
}
