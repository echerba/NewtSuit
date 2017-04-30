#include "Control.h"

Control buttons;
const int playLedPin = 13;
const int nextLedPin = 12;

int playLedState = LOW;
int nextLedState = LOW;

void setup(){
    pinMode(playLedPin, OUTPUT);
    pinMode(nextLedPin, OUTPUT);
    
    digitalWrite(playLedPin, playLedState);
    digitalWrite(nextLedPin, nextLedState);
}

void loop(){
    bool play = false;
    bool toggle = false;
    buttons.ReadControls(play,toggle);
    if(play)
    {
        playLedState = HIGH;
    }
    else
    {
        playLedState = LOW;
    }

    if(toggle)
    {
        if(nextLedState == HIGH)
            nextLedState = LOW;
        else
            nextLedState = HIGH;
    }
    //playLedState = digitalRead(8);
    //nextLedState = digitalRead(9);
    digitalWrite(playLedPin, playLedState);
    digitalWrite(nextLedPin, nextLedState);

}