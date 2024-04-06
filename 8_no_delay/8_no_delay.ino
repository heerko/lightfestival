/*
  Deze Arduino sketch maakt gebruik van TaskScheduler en Adafruit_NeoPixel om een 
  kleurveranderend "looplicht" effect te creëren op een NeoPixel LED-strip
  zonder de delay() functie te gebruiken.
  Dit zorgt voor een niet-blokkerende uitvoering, wat betekent dat de microcontroller andere taken kan verwerken
  terwijl de LEDs worden bijgewerkt, wat essentieel is voor projecten die multitasking vereisen.

  Documentatie Taskscheduler: https://github.com/arkhipenko/TaskScheduler/wiki

  Vereisten:
  - Een NeoPixel LED-strip aangesloten op de Arduino.
  - Adafruit_NeoPixel en TaskScheduler bibliotheken geïnstalleerd in de Arduino IDE.
*/

#include <TaskScheduler.h> // Laad de TaskScheduler bibliotheek
#include <Adafruit_NeoPixel.h> // Laad de Adafruit NeoPixel bibliotheek

#define PIN        6 // De pin waarop de NeoPixel LED-strip is aangesloten.
#define NUMPIXELS 16 // Het aantal pixels in de strip.

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // Initialiseert de NeoPixel strip.

// Functie die wordt uitgevoerd als de taak wordt aangeroepen.
void updateNeoPixels() {
    static int pixelIndex = 0; // Houdt de huidige actieve pixel bij.
    static uint16_t h = 0; // Houdt de huidige hue-waarde bij voor kleurvariatie.
    
    pixels.clear(); // Schakelt alle pixels uit voor het bijwerken.

    // Stelt de kleur van de huidige pixel in met een variërende hue, volle saturatie en helderheid.
    pixels.setPixelColor(pixelIndex, pixels.ColorHSV(h, 255, 255));
    pixels.show(); // Toont de bijgewerkte kleuren op de strip.
    
    pixelIndex = (pixelIndex + 1) % NUMPIXELS; // Beweegt naar de volgende pixel in de strip.
    h = (h + 100) % 65535; // Verhoogt de hue voor de volgende iteratie, met een wrap rond bij het maximum.
}

// Functie die eenmalig wordt uitgevoerd na 1 seconde.
void whiteFlash(){
  pixels.fill(pixels.Color(255, 255, 255)); // Witte kleur
  pixels.show();
}

Scheduler scheduler; // Scheduler object voor het beheren van taken.
Task tUpdateNeoPixels(50, TASK_FOREVER, &updateNeoPixels, &scheduler, true); // Taak voor het bijwerken van de LEDs om de 50ms.
Task tFlash(0, 1, &whiteFlash, &scheduler, false); // Task om na 1 seconde eemalig een actie uit te voeren.

void setup() {
  pixels.begin(); // Start de NeoPixel strip.
  tFlash.enableDelayed(1000);
}

void loop() {
  scheduler.execute(); // Voert geplande taken uit, waardoor het lichteffect doorlopend wordt bijgewerkt.
}
