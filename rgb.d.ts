
//% color=#0078D7 icon="\uf00a"
declare namespace rgb {

    //% help=basic/show-leds
    //% weight=95 blockGap=8
    //% imageLiteral=1 async
    //% blockId=device_show_leds
    //% block="show leds" icon="\uf00a"
    //% interval.defl=400 shim = rgb:: lleds
    function lleds(leds: string, interval?: number): void;


    //% help=basic/show-number
    //% weight=96
    //% blockId=device_show_number block="show|number %number" blockGap=8
    //% async
    //% interval.defl=150 shim = rgb:: showN  
    function showN(value: number, interval?: number): void;


}