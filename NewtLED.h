
#ifndef __INC_NEWTLED_H
#define __INC_NEWTLED_H

#include "Arduino.h"
#include "FastLED.h"
#include "Animation.h"

#define LED_TYPE WS2811
#define PIN3 3
#define COLORORDER = GRB


//For the NewtSuit we use 5 output pins starting at pin 3 from the Arduino Uno.

class NewtLED
{
    private:
        EOrder COLOR_ORDER = EOrder::GRB;
        static const uint8_t Pin1 = 3;
        static const uint8_t Pin2 = 4;
        static const uint8_t Pin3 = 5;
        static const uint8_t Pin4 = 6;
        static const uint8_t Pin5 = 7;

         int Strips = 5;
         int LedsPerStrip = 100;
         int LedCount = LedsPerStrip * Strips;
        const uint8_t Brightness = 64;
        
        CRGB *leds;
        IAnimationStore *animations;

    public:
        NewtLED();

};

#endif __INC_NEWTLED_H