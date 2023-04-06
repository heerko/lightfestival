/*
 * Dit programma laat een regenboog effect zien op een NeoPixel LED strip. 
 * De strip is aangesloten op pin 6 van de Arduino.
 */
 
#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define LED_COUNT 30

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // Initialiseer de NeoPixel strip
  strip.show();            // Schakel alle pixels direct uit
  strip.setBrightness(10); // Stel de helderheid in op ongeveer 1/5 (max = 255)
}

void loop() {
  // Kleurencyclus door de hele strip
  for (long eerstePixelHue = 0; eerstePixelHue < 65536; eerstePixelHue += 256) {
    // Met strip.rainbow() kun je een kleurencyclus door de strip laten lopen. 
    // De functie kan een enkel argument accepteren (de kleur van de eerste pixel) of 
    // optioneel een aantal extra argumenten accepteren, zoals het aantal kleurencyclus herhalingen (standaard 1),
    // saturatie en waarde (helderheid) (beide 0-255, vergelijkbaar met de ColorHSV() functie, standaard 255),
    // en een true/false vlag om gamma-correctie toe te passen voor "echtere" kleuren (standaard waar).
    strip.rainbow(eerstePixelHue);
    strip.show(); // Stuur de data naar de strip
    delay(10);  // Even wachten
  }
}
