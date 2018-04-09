#include "pxt.h"


/**
 * Provides access to basic micro:bit functionality.
 */
//% color=#0078D7 weight=100 icon="\uf00a"
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
    void showNumber(int value, int interval = 150) {
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
    void showLeds(ImageLiteral leds, int interval = 400) {
      uBit.display.print(MicroBitImage(imageBytes(leds)), 0, 0, 0, interval);
    }


    
}