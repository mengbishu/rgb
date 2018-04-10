#include "pxt.h"


/**
 * Provides access to basic micro:bit functionality.
 */
//% color=#0078D7 icon="\uf00a"
namespace rgb {
    /**
     * Scroll a number on the screen. If the number fits on the screen (i.e. is a single digit), do not scroll.
     * @param interval speed of scroll; eg: 150, 100, 200, -100
     */
    //% help=basic/show-number
    //% weight=96
    //% blockId=device_show_number block="show|number %number" blockGap=8
    //% async
    //% parts="ledmatrix"
    void showN(int value, int interval = 150) {
      if (interval <= 0)
        interval = 1;
      ManagedString t(value);
      if (value < 0 || value >= 10) {
        uBit.display.scroll(t, interval);
      } else {
        uBit.display.printChar(t.charAt(0), interval * 5);
      }
    }



    /**
     * Draws an image on the LED screen.
     * @param leds the pattern of LED to turn on/off
     * @param interval time in milliseconds to pause after drawing
     */
    //% help=basic/show-leds
    //% weight=95 blockGap=8
    //% imageLiteral=1 async
    //% blockId=device_show_leds
    //% block="show leds" icon="\uf00a"
    //% parts="ledmatrix"
    void lleds(ImageLiteral leds, int interval = 400) {
      uBit.display.print(MicroBitImage(imageBytes(leds)), 0, 0, 0, interval);
    }

    /**
     * Creates an image that fits on the LED screen.
     */
    //% weight=75 help=images/create-image
    //% blockId=device_build_image block="create image"
    //% parts="ledmatrix"
    Image createI(ImageLiteral leds) {
        return MicroBitImage(imageBytes(leds)).clone().leakData();
    }

    /**
     * Creates an image with 2 frames.
     */
    //% weight=74 help=images/create-big-image
    //% blockId=device_build_big_image block="create big image" imageLiteral=2
    //% parts="ledmatrix"
    Image createBigI(ImageLiteral leds) {
        return createI(leds);
    }
    
}