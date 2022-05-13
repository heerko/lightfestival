/*
 * In dit voorbeeld worden de pixels om de beurt groen
 * dvm een loop.
 * 
 * Oefeningen: 
 * - Hoe verander je de kleur?
 * - Hoe verander je de snelheid waarmee het lichtje over de strip beweegt?
 * - Hoe kan je het lichtje maar toch halverwege de strip laten gaan?
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

void setup() {
  pixels.begin(); // "start" de library
}

void loop() {
  // Zet voor de zekerheid alle pixels op zwart.
  pixels.clear();
  // De for-loop hieronder maakt een 'teller' met de variablenaam i.
  // De teller telt van 0 tot de laatste pixel (i< NUMPIXELS)
  // aan het einde van elke loop wordt i 1 hoger (i++) 
  for(int i=0; i<NUMPIXELS; i++) { 
    // maak de 'i-ste' pixel groen.  
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    // stuur het naar de strip;
    pixels.show();
    // wacht heel even
    delay(500);
    // en zet de pixel weer uit.
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
}
