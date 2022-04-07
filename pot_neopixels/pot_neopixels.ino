// De potmeter wordt alsvolgt aangesloten: 
// Pot -> Arduino
// 1 -> GND
// 2 -> A0
// 3 -> 5V

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6
#define POT        A0

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 30

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // alle pixels uit
  int pot = analogRead(A0); // meet waarde potmeter, waarde is tussen 0 en 1023
  int led = map(pot, 0, 1023, 0, NUMPIXELS ); // map de waarde van de potmeter naar een pixel op de strip. 0V -> pixel 0, 5V (1023) -> laatste pixel
  pixels.setPixelColor(led, pixels.Color(255, 0, 255)); // de gemapte pixel krijgt een kleur
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // even wachten
}
