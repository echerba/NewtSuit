#include "NewtLED.h"


NewtLED *ledstrings;

 void setup(){
    ledstrings = new NewtLED();
    return;    
 }

 void loop(){
    ledstrings->Loop();
 }
