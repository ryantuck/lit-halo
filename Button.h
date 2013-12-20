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
    
	bool pressed;
    bool released;
    bool lastButtonState;
	
	void checkState();
    
    
};


#endif
