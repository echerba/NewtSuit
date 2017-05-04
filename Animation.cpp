#include "Animation.h"

AnimationSD::AnimationSD(CRGB* ledsArray, int ledArrayCount)
{
    
    leds = ledsArray;
    ledCount = ledArrayCount;
    pinMode(10,OUTPUT);
    SD.begin(10); //Should add error handling in here.
    animationRoot = SD.open(AnimationDir);
    animation = null;
    NextAnimation;
}

AnimationSD::NextFrame()
{
    animation.readBytes((char*)leds,ledCount);
}

AnimationSD::NextAnimation()
{
    if(animation)
    {
        animation.close();
    }
    
    animation = animationRoot.openNextFile();
    if(!animation) //We have gone through all animations so reopen to loop
    {
        animationRoot.close();
        animationRoot = SD.open(AnimationDir);
        animation = animationRoot.openNextFile();
    }
}