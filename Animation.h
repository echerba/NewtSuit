#ifndef __INC_ANIMATION_H
#define __INC_ANIMATION_H

#include "Arduino.h"
#include "FastLED.h"
//#include <SPI.h>
#include <SD.h>
#include <string.h>



class IAnimationStore
{
    public:
        virtual ~IAnimationStore(){}
        virtual void NextFrame()=0;
        virtual void NextAnimation()=0;
};

class AnimationSD : public IAnimationStore
{
    public:
        AnimationSD(CRGB* ledsArray, int ledArrayCount);
        ~AnimationSD(){}
        void NextFrame();
        void NextAnimation();

    private:
        const String AnimationDir = "ANIMAT~1";
        CRGB* leds;
        int ledCount;

        File animationRoot;
        File animation;       
};

#endif __INC_ANIMATION_H
