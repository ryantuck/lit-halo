//	########################################################################

//  Thing.cpp

//	4/23/13

//	########################################################################

#include "Thing.h"


Thing::Thing()
{
	io			= 1;
	layer		= 1;
	period		= 1;
	brightness	= 100;
	
	numLEDs = 16;			//	shouldn't be member
	
}


//	Could probably be made less redundant
void Thing::setBlock(Color aColor, byte aBrightness, byte aStart, byte aEnd)
{
	// check values
	if (aStart	< 0)			aStart	= 0;
	if (aStart	>= numLEDs)		aStart	= numLEDs;
	if (aEnd	< 0)			aEnd	= 0;
	if (aEnd	>= numLEDs)		aEnd	= numLEDs;
	
	//	update LEDs color and brightness
	if (aStart <= aEnd)						//	doesn't wrap
	{
		for (int n=aStart;n<=aEnd;n++)
		{
			leds[n].color.setColor(aColor);
			leds[n].brightness = aBrightness;
		}
	}
	else									//	wraps
	{
		for (int n=aStart;n<numLEDs;n++)
		{
			leds[n].color.setColor(aColor);
			leds[n].brightness = aBrightness;
		}
		for (int n=0;n<=aEnd;n++)
		{
			leds[n].color.setColor(aColor);
			leds[n].brightness = aBrightness;
		}
	}
}


void Thing::move(bool direction)
{
	LED tmpLED;
	int maxAddress = numLEDs-1;
	
	if (direction)
	{
		tmpLED.color.setColor(leds[maxAddress].color);
		tmpLED.brightness = leds[maxAddress].brightness;
		
		for (int n=maxAddress;n>0;n++)
		{
			leds[n].color.setColor(leds[n-1].color);
			leds[n].brightness = leds[n-1].brightness;
		}
		
		leds[0].color.setColor(tmpLED.color);
		leds[0].brightness = tmpLED.brightness;
	}
	else
	{
		tmpLED.color.setColor(leds[0].color);
		tmpLED.brightness = leds[0].brightness;
		
		for (int n=0;n<maxAddress;n++)
		{
			leds[n].color.setColor(leds[n+1].color);
			leds[n].brightness = leds[n+1].brightness;
		}
		
		leds[maxAddress].color.setColor(tmpLED.color);
		leds[maxAddress].brightness = tmpLED.brightness;
	}
}








































