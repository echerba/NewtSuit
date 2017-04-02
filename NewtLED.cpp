#ifndef __INC_NEWTLED_H
#define __INC_NEWTLED_H
#include "FastLED.h"
#include "NewtLED.h"

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

void setup_newtled() {
  // tell FastLED there's 60 NEOPIXEL leds on pin 10, starting at index 0 in the led array
  FastLED.addLeds<LED_TYPE, PIN1,COLOR_ORDER>(leds, 0*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<LED_TYPE, PIN2,COLOR_ORDER>(leds, 1*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<LED_TYPE, PIN3,COLOR_ORDER>(leds, 2*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<LED_TYPE, PIN4,COLOR_ORDER>(leds, 3*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<LED_TYPE, PIN5,COLOR_ORDER>(leds, 4*NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.setBrightness( BRIGHTNESS );
    
}

#endif __INC_NEWTLED_H
