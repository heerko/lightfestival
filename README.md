# lightfestival

Example files for HKU lightfestival. 

![basic breadboard setup](images/Neopixels%20basic.png)
Basic breadboard layout for a small number of pixels. 

__IMPORTANT__: When using a large number of pixels, to reduce NeoPixel burnout risk, add 1000 uF capacitor across pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
and minimize distance between Arduino and first pixel.  Avoid connecting
on a live circuit...if you must, connect GND first.
For the ultimate NeoPixel guide, check out:
https://learn.adafruit.com/adafruit-neopixel-uberguide/overview
