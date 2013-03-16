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
    
    debounceDelay = 5; //ms
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
		if (pressedCounter == 50)
			pressedCounter = 0;
	}
	
	lastState = state;
    
//    bool reading = digitalRead(pin);
//    
//    //if the switch changed due to noise or pressing
//    if(reading != lastButtonState)
//    {
//        //reset debounce time
//        lastDebounceTime = millis();
//
//    }
//    
//    if(abs(millis() - lastDebounceTime) > debounceDelay)
//    {
//        buttonState = reading;
//    }
//    
//    //detect high to low transition
//    if(lastButtonState == 1 && buttonState == 0)
//    {
//        pressed = 1;
//	}
//    else
//    {
//        pressed = 0;
//    }
//    
//    lastButtonState = reading;
	
}





