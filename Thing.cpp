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
			leds[n].set(aColor,aBrightness);
	}
	else									//	wraps
	{
		for (int n=aStart;n<numLEDs;n++)
			leds[n].set(aColor,aBrightness);
		for (int n=0;n<=aEnd;n++)
			leds[n].set(aColor,aBrightness);
	}
}


void Thing::move(bool direction)
{
	LED tmpLED;
	int maxAddress = numLEDs-1;
	
	if (direction)
	{
		tmpLED.set(leds[maxAddress]);
		
		for (int n=maxAddress;n>0;n++)
			leds[n].set(leds[n-1]);
		
		leds[0].set(tmpLED);
	}
	else
	{
		tmpLED.set(leds[0]);
		
		for (int n=0;n<maxAddress;n++)
			leds[n].set(leds[n+1]);
		
		leds[maxAddress].set(tmpLED);
	}
}

void Thing::move(bool direction,byte units)
{
	if		(units < 0)			units = 0;
	while	(units > numLEDs)	units -= numLEDs;
	
	for (int n=0;n<units;n++)
		move(direction);
}


void Thing::fade(bool direction)
{
	brightness = updateValue(brightness, direction, 0, 100, 0);
}

void Thing::fade(bool direction, byte units)
{
	if		(units < 0)			units = 0;
	while	(units > 100)		units -= 100;
	
	for (int n=0;n<units;n++)
		fade(direction);
}





byte Thing::updateValue(byte parameter,
						  bool direction,
						  byte minVal,
						  byte maxVal,
						  bool cycles)
{
	if (direction)
	{
		if (parameter == maxVal)
		{
			if (cycles) parameter = minVal;
			else		parameter = maxVal;
		}
		else parameter++;
	}
	else
	{
		if (parameter == minVal)
		{
			if (cycles)	parameter = maxVal;
			else		parameter = minVal;
		}
		else parameter--;
	}
	
	return parameter;
}


































