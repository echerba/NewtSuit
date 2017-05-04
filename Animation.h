#ifndef __INC_ANIMATION_H
#define __INC_ANIMATION_H

#include "Arduino.h"
#include "FastLED.h"
#include <SPI.h>
#include <SD.h>
#include <string.h>



class AnimationStoreInterface
{
    public:
        AnimationInterface(CRGB* ledsArray, int ledArrayCount){}
        virtual ~AnimationInterface(){}
        virtual void NextFrame()=0;
        virtual void NextAnimation()=0;
};

class AnimationSD
{
    public:
        AnimationSD(CRGB* ledsArray, int ledArrayCount){}
        ~AnimationSD(){}

    private:
        const string AnimationDir = "animations";
        CRGB* leds;
        int ledCount;

        File animationRoot;
        File animation;       
};

#endif __INC_ANIMATION_H
