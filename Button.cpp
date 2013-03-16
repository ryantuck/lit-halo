//	####################################################################
//
//	Button.cpp
//
//	####################################################################


#include "Button.h"

Button::Button()
{
    lastButtonState = 1;
    
    pressed		= 0;
    released	= 0;
}

Button::Button(int newPin)
{
	pin = newPin;
	pinMode(pin, INPUT);
	digitalWrite(pin, HIGH);

    lastButtonState = 1;
}

void Button::checkState()
{
    
    bool reading = digitalRead(pin);
    
    if(reading != lastButtonState)
    {
        if(!reading) pressed = 1;
        if(reading) released = 1;
    }
    else
    {
        pressed		= 0;
        released	= 0;
    }
    lastButtonState = reading;
    
    if(pressed)		Serial.println("button pressed");
    if(released)	Serial.println("button released");
}


