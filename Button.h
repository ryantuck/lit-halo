//	####################################################################
//
//	Button.h
//
//	####################################################################


#ifndef __Hardware__Button__
#define __Hardware__Button__

#include "Arduino.h"

class Button
{
private:
	byte pin;
public:
	Button();
	Button(int pin);
	bool state;
	bool lastState;
	bool pressed;
	byte pressedCounter;
    
    int lastDebounceTime;
	
	void checkState();
    
    //kern's new members
    bool buttonState;
    bool lastButtonState;
    int lastDebouceTime;
    int debounceDelay;
};


#endif
