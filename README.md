#Lightfestival

Voorbeeldbestanden voor HKU lichtfestival.

In deze repository vindt je een aantal voorbeelden voor het werken met neopixels. Alle voorbeelden zijn voorzien van comments die de werking uitleggen. 
De eerste voorbeelden hebben een aantal 'opdrachten' in comments in de code, deze zou je kunnen gebruiken om de code te leren kennen.

Je kan deze repo downloaden met groene de knop "<> Code" rechtsboven, klik daarop, en klik dan op Download Zip. Je kan natuurlijk ook kopieren en plakken als dat meer je ding is :)

Hieronder de nette manier om een ledstrip aan te sluiten. De weerstand beschermt 
![basis breadboard setup](images/Neopixels%20basic.png)
Basic breadboard layout voor een klein aantal pixels.

__BELANGRIJK__: 
Bij gebruik van een groot aantal pixels, om het risico op doorbranden van de NeoPixel te verminderen, voeg je 1000 uF condensator toe over de voedingskabels van de pixel. En je voegt een weerstand van 300 - 500 Ohm toe aan de data input lijn van de eerste pixel.

Minimaliseer de afstand tussen Arduino en de eerste pixel. 
Sluit de leds alleen aan als de Arduino 'uit' is... als het toch moet, sluit dan eerst GND aan.

Ga voor de ultieme NeoPixel-gids naar:
https://learn.adafruit.com/adafruit-neopixel-uberguide/overview