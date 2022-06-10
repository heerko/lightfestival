// Adafruit_NeoMatrix example for single NeoPixel Shield.
// By Marc MERLIN <marc_soft@merlins.org>
// Contains code (c) Adafruit, license BSD

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

// Choose your prefered pixmap
//#include "heart24.h"
//#include "yellowsmiley24.h"
//#include "bluesmiley24.h"
#include "smileytongue24.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN    6

// Max is 255, 32 is a conservative value to not overload
// a USB power supply (500mA) for 12x12 pixels.
#define BRIGHTNESS 10

// MATRIX DECLARATION:
// Parameter 1 = width of EACH NEOPIXEL MATRIX (not total display)
// Parameter 2 = height of each matrix
// Parameter 3 = number of matrices arranged horizontally
// Parameter 4 = number of matrices arranged vertically
// Parameter 5 = pin number (most are valid)
// Parameter 6 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the FIRST MATRIX; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs WITHIN EACH MATRIX are
//     arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns WITHIN
//     EACH MATRIX proceed in the same order, or alternate lines reverse
//     direction; pick one.
//   NEO_TILE_TOP, NEO_TILE_BOTTOM, NEO_TILE_LEFT, NEO_TILE_RIGHT:
//     Position of the FIRST MATRIX (tile) in the OVERALL DISPLAY; pick
//     two, e.g. NEO_TILE_TOP + NEO_TILE_LEFT for the top-left corner.
//   NEO_TILE_ROWS, NEO_TILE_COLUMNS: the matrices in the OVERALL DISPLAY
//     are arranged in horizontal rows or in vertical columns, respectively;
//     pick one or the other.
//   NEO_TILE_PROGRESSIVE, NEO_TILE_ZIGZAG: the ROWS/COLUMS OF MATRICES
//     (tiles) in the OVERALL DISPLAY proceed in the same order for every
//     line, or alternate lines reverse direction; pick one.  When using
//     zig-zag order, the orientation of the matrices in alternate rows
//     will be rotated 180 degrees (this is normal -- simplifies wiring).
//   See example below for these values in action.
// Parameter 7 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 pixels)
//   NEO_GRB     Pixels are wired for GRB bitstream (v2 pixels)
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA v1 pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)

// Define matrix width and height.
#define mw 8
#define mh 32
Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(mw, mh,
    LED_PIN,
    NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
    NEO_RGBW            + NEO_KHZ800 );

// Scroll within big bitmap so that all if it becomes visible or bounce a small one.
// If the bitmap is bigger in one dimension and smaller in the other one, it will
// be both panned and bounced in the appropriate dimensions.
void display_panOrBounceBitmap (uint8_t bitmapSize) {
  // keep integer math, deal with values 16 times too big
  // start by showing upper left of big bitmap or centering if the display is big
  int16_t xf = max(0, (mw - bitmapSize) / 2) << 4;
  int16_t yf = max(0, (mh - bitmapSize) / 2) << 4;
  // scroll speed in 1/16th
  int16_t xfc = 6;
  int16_t yfc = 3;
  // scroll down and right by moving upper left corner off screen
  // more up and left (which means negative numbers)
  int16_t xfdir = -1;
  int16_t yfdir = -1;

  for (uint16_t i = 1; i < 200; i++) {
    bool updDir = false;

    // Get actual x/y by dividing by 16.
    int16_t x = xf >> 4;
    int16_t y = yf >> 4;

    matrix->clear();
    // pan 24x24 pixmap
    if (bitmapSize == 24) matrix->drawRGBBitmap(x, y, (const uint16_t *) bitmap24, bitmapSize, bitmapSize);
    matrix->show();

    // Only pan if the display size is smaller than the pixmap
    // but not if the difference is too small or it'll look bad.
    if (bitmapSize - mw > 2) {
      xf += xfc * xfdir;
      if (xf >= 0)                      {
        xfdir = -1;
        updDir = true ;
      };
      // we don't go negative past right corner, go back positive
      if (xf <= ((mw - bitmapSize) << 4)) {
        xfdir = 1;
        updDir = true ;
      };
    }
    if (bitmapSize - mh > 2) {
      yf += yfc * yfdir;
      // we shouldn't display past left corner, reverse direction.
      if (yf >= 0)                      {
        yfdir = -1;
        updDir = true ;
      };
      if (yf <= ((mh - bitmapSize) << 4)) {
        yfdir = 1;
        updDir = true ;
      };
    }
    // only bounce a pixmap if it's smaller than the display size
    //    if (mw > bitmapSize) {
    //      xf += xfc * xfdir;
    //      // Deal with bouncing off the 'walls'
    //      if (xf >= (mw - bitmapSize) << 4) {
    //        xfdir = -1;
    //        updDir = true ;
    //      };
    //      if (xf <= 0)           {
    //        xfdir =  1;
    //        updDir = true ;
    //      };
    //    }
    //    if (mh > bitmapSize) {
    //      yf += yfc * yfdir;
    //      if (yf >= (mh - bitmapSize) << 4) {
    //        yfdir = -1;
    //        updDir = true ;
    //      };
    //      if (yf <= 0)           {
    //        yfdir =  1;
    //        updDir = true ;
    //      };
    //    }

    if (updDir) {
      // Add -1, 0 or 1 but bind result to 1 to 1.
      // Let's take 3 is a minimum speed, otherwise it's too slow.
      xfc = constrain(xfc + random(-1, 2), 3, 16);
      yfc = constrain(xfc + random(-1, 2), 3, 16);
    }
    delay(10);
  }
}


void loop() {
  // pan a big pixmap
  display_panOrBounceBitmap(24);

}

void setup() {
  Serial.begin(115200);
  matrix->begin();
  matrix->setBrightness(BRIGHTNESS);
  matrix->clear();
}
