/*
 * Tiny4kOLED - Drivers for SSD1306 controlled dot matrix OLED/PLED 128x32 displays
 *
 * Based on ssd1306xled, re-written and extended by Stephen Denne
 * from 2017-04-25 at https://github.com/datacute/Tiny4kOLED
 *
 */

#ifndef SOLOMON_SYSTECH_H
#define SOLOMON_SYSTECH_H


const uint8_t trex[] PROGMEM = {
  
  0xDF, 0xFD, 0xBC, 0xDF, 0x11, 0x08
  
};


const uint8_t pacman[] PROGMEM = {
  0x18, 0x3C, 0x7E, 0xFF, 0xA7, 0x66, 0x24
};

const uint8_t citrouille[] PROGMEM = {
 0x3C, 0x42, 0x91, 0x45, 0x85, 0x91, 0x42, 0x3C
};




#endif
