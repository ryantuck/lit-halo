//	####################################################################
//
//	LED.cpp
//
//	####################################################################

#include "LED.h"

LED::LED()
{
	brightness		= 100;
	currentLayer	=   1;
	color.setColor(1,69,100);
}

LED::LED(Color newColor, byte newBrightness, byte newLayer)
{
	if (newLayer <  1)			newLayer =  1;
	if (newLayer > 10)			newLayer = 10;
	
	if (newBrightness <   0)	newBrightness =   0;
	if (newBrightness > 100)	newBrightness = 100;
	
	color			= newColor;
	brightness		= newBrightness;
	currentLayer	= newLayer;
}



void LED::printVitals()
{
	color.printVitals();
	Serial.print("Brightness:   ");
	if (brightness < 10) Serial.print("  ");
	else if (brightness < 100) Serial.print(" ");
	Serial.println(brightness);
	Serial.print("Current Layer:  ");
	Serial.println(currentLayer);
	Serial.println();	
}
