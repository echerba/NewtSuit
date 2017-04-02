
#include "FastLED.h"

#define NUM_STRIPS 5
#define NUM_LEDS_PER_STRIP 100
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS
#define BRIGHTNESS  64
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
//For the NewtSuit we use 5 output pins starting at pin 3 from the Arduino Uno.
#define PIN1 3
#define PIN2 4
#define PIN3 5
#define PIN4 6
#define PIN5 7


void setup_newtled();
