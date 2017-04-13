#include "Control.h"

Control *Buttons;
const int playLedPin = 13;
const int nextLedPin = 12;

int playLedState = LOW;
int nextLedState = LOW;

void setup(){
    pinMode(playLedPin, OUTPUT);
    pinMode(nextLedPin, OUTPUT);
    Buttons = new Control();

    digitalWrite(playLedPin, playLedState);
    digitalWrite(nextLedPin, nextLedState);
}

void loop(){
    bool play = FALSE;
    bool toggle = FALSE;
    Buttons.ReadControls(play,toggle);
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
        nextLedState = HIGH;
    }
    else
    {
        nextLedState = LOW;
    }
    digitalWrite(playLedPin, playLedState);
    digitalWrite(nextLedPin, nextLedState);

}