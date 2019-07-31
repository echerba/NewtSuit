#include "NewtLED.h"

NewtLED::NewtLED() {
  
  Serial.begin(9600);
  
  delay(3000); // sanity delay
  
  Serial.println("/NewtLED()");
  
  
   leds = new CRGB[NewtLED::LedCount];
  // tell FastLED there's 100 NEOPIXEL leds on each pin.
  //FastLED.addLeds<LED_TYPE, Pin1>(leds, 0, LedCount);
  FastLED.addLeds<LED_TYPE, Pin1>(leds, 0, LedsPerFrontStrip);
  FastLED.addLeds<LED_TYPE, Pin2>(leds, LedsPerFrontStrip, LedsPerBackStrip);
  FastLED.addLeds<LED_TYPE, Pin3>(leds, LedsPerFrontStrip+LedsPerBackStrip, LedsPerBackStrip);
  FastLED.addLeds<LED_TYPE, Pin4>(leds, LedsPerFrontStrip+LedsPerBackStrip+LedsPerBackStrip, LedsPerFrontStrip);
  
  FastLED.setBrightness( Brightness );

  //FastLED.addLeds<LED_TYPE, Pin5>(leds, 0*LedsPerStrip, LedsPerStrip);
  
  buttons = new Control();  
  
  animations = new AnimationSD(leds,LedCount);
  
  Serial.println("/NewtLED()");
  
}

int NewtLED::Loop()
{
  
  static bool playing = true;
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
    delay(200);
  }
}
