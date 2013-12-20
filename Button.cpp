//	####################################################################
//
//	Button.cpp
//
//	####################################################################


#include "Button.h"

Button::Button()
{
<<<<<<< HEAD
	
=======
    lastButtonState = 0;
    
    pressed		= 0;
    released	= 0;
>>>>>>> ryanDev
}

Button::Button(int newPin)
{
	pin = newPin;
	pinMode(pin, INPUT);
	digitalWrite(pin, HIGH);
<<<<<<< HEAD
=======

    lastButtonState = 0;
    pressed         = 0;
    released        = 0;
>>>>>>> ryanDev
}

void Button::checkState()
{
	state	= digitalRead(pin);
	pressed = 0;
	
	if (pressedCounter == 0)
	{
		if (state == LOW)
		{
			pressed = 1;
			pressedCounter = 1;
		}
	}
	else
	{
		pressedCounter++;
		if (pressedCounter == 30)
			pressedCounter = 0;
	}
	
	lastState = state;
	
}





