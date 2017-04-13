
class Control
{

private:
    const int PlayPin = 8;
    const int NextPin = 9;

bool play = FALSE;
int playButtonState;             // the current reading from the input pin
int lastPlayButtonState = LOW;   // the previous reading from the input pin
int nextButtonState;             // the current reading from the input pin
int lastNextButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

public:
    void Control();
    void ReadControls(bool&play, bool&toggleNext);

}