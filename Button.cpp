//	####################################################################
//
//	Button.cpp
//
//	####################################################################


#include "Button.h"

Button::Button()
{
	
}

Button::Button(int newPin)
{
	pin = newPin;
	pinMode(pin, INPUT);
	digitalWrite(pin, HIGH);
}

void Button::checkState()
{
	state	= digitalRead(pin);
	pressed = 0;
	
	if (pressedCounter == 0)
	{
		if (state == HIGH)
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





