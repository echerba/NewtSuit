#include "NewtLED.h"

NewtLED::NewtLED() {

  leds = new CRGB[NewtLED::LedCount];
  // tell FastLED there's 100 NEOPIXEL leds on each pin.
  FastLED.addLeds<LED_TYPE, Pin1>(leds, 0*LedsPerStrip, LedsPerStrip);
  FastLED.addLeds<LED_TYPE, Pin2>(leds, 1*LedsPerStrip, LedsPerStrip);
  FastLED.addLeds<LED_TYPE, Pin3>(leds, 2*LedsPerStrip, LedsPerStrip);
  FastLED.addLeds<LED_TYPE, Pin4>(leds, 3*LedsPerStrip, LedsPerStrip);
  FastLED.addLeds<LED_TYPE, Pin5>(leds, 4*LedsPerStrip, LedsPerStrip);
  FastLED.setBrightness( Brightness );
  
  buttons = new Control();  
  animations = new AnimationSD(leds,LedCount);
}

int NewtLED::Loop()
{
  bool playing = false;
  bool nextAnimation = false;

  buttons->ReadControls(playing,nextAnimation);
  if(nextAnimation)
  {
    animations->NextAnimation();
  }
  if(playing)
  {
    animations->NextFrame();
    FastLED.show();
    //This all needs to be updated based on the real delays.
    delay(100);
  }
}