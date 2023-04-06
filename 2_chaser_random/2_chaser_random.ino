/*
 * Dit voorbeeld doet vrijwel hetzelfde als 1_Chaser maar 
 * de code is iets anders geschreven. 
 * En er wordt steeds een random kleur gekozen voor elke pixel.
 * 
 * Oefening:
 * - Probeer 'vuur' te maken door de kleuren aan te passen
 * - Probeer 'water' te maken
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
  // De for-loop hieronder maakt een 'teller' met de variablenaam "i".
  // De teller telt van 0 tot de laatste pixel (i< NUMPIXELS)
  // aan het einde van elke loop wordt "i" 1 hoger (i++) 
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    // maak de 'i-ste' pixel een random kleur.  
    // elk kleurkanaal kan een waarde hebben tussen 0 en 255.
    // random(255) kiest een willekeurig waarde tussen 0 en 255.
    pixels.setPixelColor(i, pixels.Color(random(255), random(255), random(255)));
    // stuur het naar de strip;
    pixels.show();   // Send the updated pixel colors to the hardware.
    // wacht heel even
    delay(50);
    // en zet de pixel weer uit.
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
}
