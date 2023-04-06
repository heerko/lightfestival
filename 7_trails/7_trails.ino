// Laad de NeoPixel library
#include <Adafruit_NeoPixel.h>

// Definieer de pin waarop de LED-strip is aangesloten en het aantal pixels in de strip
#define PIN 6
#define NUMPIXELS 30

// Creëer een object van de Adafruit_NeoPixel class met het aantal pixels en de pin als parameters
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialiseer de NeoPixel library
  pixels.begin();
}

// Initialiseer de variabelen voor de kleuren rood, groen en blauw
int r, g, b = 0;

void loop() {
  // Schuif de kleur van elke pixel op naar de volgende pixel
  for (int i = NUMPIXELS; i > 0; i--) {
    pixels.setPixelColor(i, pixels.getPixelColor(i - 1));
  }

  // Controleer of er een nieuwe kleur gegenereerd moet worden of niet
  if (random(50) == 0) {
    // Als er een nieuwe kleur gegenereerd moet worden, kies willekeurige waarden voor rood, groen en blauw
    r = random(255);
    g = random(255);
    b = random(255);
  } else {
    // Als er geen nieuwe kleur gegenereerd moet worden, verminder de helderheid van de huidige kleur met 70%
    r *= 0.7;
    g *= 0.7;
    b *= 0.7;
  }

  // Stel de kleur van de eerste pixel in op basis van de waarden van rood, groen en blauw
  pixels.setPixelColor(0, pixels.Color(r, g, b));

  // Laat de kleuren op de LED-strip zien
  pixels.show();

  // Voeg een vertraging van 10 milliseconden toe tussen elke iteratie van de loop
  delay(10);
}