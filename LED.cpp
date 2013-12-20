//	####################################################################
//
//	LED.cpp
//
//	####################################################################

#include "LED.h"

LED::LED()
{
	brightness = maxBrightness;
	color.setColor(1,69,100);
}

LED::LED(Color newColor, byte newBrightness)
{
	if (newBrightness < 0)				newBrightness = 0;
	if (newBrightness > maxBrightness)	newBrightness = maxBrightness;
	
	color			= newColor;
	brightness		= newBrightness;
}

void LED::adjustColor()
{
	// adjusts r,g,b values based on brightness
	
	float ratio = (float) brightness / maxBrightness;
		
	color.r *= ratio;
	color.g *= ratio;
	color.b *= ratio;
}

void LED::mixWith(LED aLED)
{
	adjustColor();
	aLED.adjustColor();
	
	if (aLED.brightness > brightness)
		brightness = aLED.brightness;

	
	color.mixWith(aLED.color);
}

void LED::setAttributes(LED aLED)
{
	color.setColor(aLED.color);
	brightness = aLED.brightness;
}

void LED::setAttributes(Color aColor,byte aBrightness)
{
	color.setColor(aColor);
	brightness = aBrightness;
}

void LED::printVitals()
{
	color.printVitals();
	Serial.print("Brightness:   ");
	if (brightness < 10) Serial.print("  ");
	else if (brightness < 100) Serial.print(" ");
	Serial.println(brightness);
	Serial.println();	
}



AddressedLED::AddressedLED()
{
	address = 0;
}

AddressedLED::AddressedLED(byte a)
{
	address = a;
}

LayeredLED::LayeredLED()
{
	layer = 1;
}

LayeredLED::LayeredLED(byte l)
{
	layer = l;
}





