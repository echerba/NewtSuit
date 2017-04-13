#include "Control.h"

Control::Control()
{
    pinMode(PlayPin, INPUT);
    pinMode(NextPin, INPUT);
}

void Control::ReadControls(bool&play, bool&toggleNext)
{
    int playReading = digitalRead(PlayPin);
    int nextReading = digitalRead(NextPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (playReading != lastPlayButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (playReading != lastPlayButtonState) {
      lastPlayButtonState = playReading;

      // only toggle the play or pause if the new button state is HIGH
      if (playButtonState == HIGH) {
        playState = !playState;
      }
      if (nextButtonState == HIGH) {
        toggleNext = true;
      }
    }
  }

  play = playState;
}

