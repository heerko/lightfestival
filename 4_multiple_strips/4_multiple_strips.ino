/* In dit voorbeeld hebben we twee strips met de Arduino verbonden.
 *  De eerste strip heeft 24 pixels en is verbonden met aan pin 6,
 *  de tweede heeft maar 8 pixels en is verbonden aan pin 7.
 */
// laad de NeoPixel library
#include <Adafruit_NeoPixel.h>

// de ledstrip heeft 3 draden. 2 zijn verbonden met 5V en GND, de laatste gaat naar pin 6 of 7.
#define PIN1        6
#define PIN2        7

// Hoeveel leds zitten er op de strip?
#define NUMPIXELS1 24
#define NUMPIXELS2 8

// Vertel je de Arduino dat je een Neopixel strip hebt aangesloten
// Hiervoor heeft de library drie argumenten nodig:
// - hoeveel pixels, dat hebben we hierboven opgeslagen in de constant NUMPIXELS
// - welke pin, dat is de constante PIN
// - en het laatste geeft de soort neopixels aan. Dit kan je meestal gewoon copy/pasten
Adafruit_NeoPixel pixels1(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
// hetzelfde voor de tweede strip, let op NUMPIXELS2 en PIN2.
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels1.begin(); // "start" de library voor eerste strip
  pixels2.begin(); // zelfde voor de tweede strip.
}

void loop() {
  // Zet voor de zekerheid alle pixels op zwart.
  pixels1.clear();
  pixels2.clear();
  
  // De for-loop hieronder maakt een 'teller' met de variablenaam i.
  // De teller telt van 0 tot de laatste pixel (i< NUMPIXELS)
  // aan het einde van elke loop wordt i 1 hoger (i++)
  // eerst voor de eerste strip...
  for (int i = 0; i < NUMPIXELS1; i++) {
    // maak de 'i-ste' pixel groen.
    pixels1.setPixelColor(i, pixels1.Color(0, 150, 0));
    // stuur het naar de strip;
    pixels1.show();
    // wacht heel even
    delay(50);
    // en zet de pixel weer uit.
    pixels1.setPixelColor(i, pixels1.Color(0, 0, 0));
    pixels1.show();
  }
  // daarna voor de tweede strip. Let ook hier weer op NUMPIXELS2, pixels2. 
  for (int i = 0; i < NUMPIXELS2; i++) {
    // maak de 'i-ste' pixel groen.
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 150));
    // stuur het naar de strip;
    pixels2.show();
    // wacht heel even
    delay(50);
    // en zet de pixel weer uit.
    pixels2.setPixelColor(i, pixels1.Color(0, 0, 0));
    pixels2.show();
  }
}
