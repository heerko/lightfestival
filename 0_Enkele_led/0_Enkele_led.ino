/* 
 *  Super basic voorbeeld. We laten de eerste led van de strip rood/groen knipperen. 
 *  
 *  De ledstrip is aangesloten op 5V, GND en de data pin van de strip op pin 6 van de Arduino
 */

// laad de NeoPixel library
#include <Adafruit_NeoPixel.h>

// de ledstrip heeft 3 draden. 2 zijn verbonden met 5V en GND, de laatste gaat naar pin 6.
#define PIN        6

// Hoeveel leds zitten er op de strip?
// in dit voorbeeld gebruiken we alleen de eerste...
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
  pixels.clear(); // Alle pixels op zwart (uit)

  // Kleuren geef je aan in RGB waardes in de volgorde
  // Rood, Groen, Blauw. De waarde kan tussen 0 (helemaal uit) en 255 (helemaal aan) zitten.
  // dus pixels.Color(0, 150, 0) betekend: geen rood, +- 75% groen en geen blauw.
  //
  // Je telt de pixels vanaf 0, dus de 0 hieronder staat voor de eerste pixel:
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));
  pixels.show(); // Stuur de data naar de strip

  delay(1000); // Even wachten

  pixels.setPixelColor(0, pixels.Color(150, 0, 0)); // color(150,0,0) Rood, maar geen groen of blauw.
  pixels.show(); // Stuur de data naar de strip

  delay(1000); // Weer even wachten
}
