//	########################################################################

//  Thing.cpp

//	4/23/13

//	########################################################################

#include "Thing.h"


Thing::Thing()
{
	io				= 1;
	layer			= 1;
	period			= 1;
	brightness		= maxBrightness;
	readyToDie		= 0;
	
	periodCounter	= 0;

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
			tLEDs[n].setAttributes(aColor,aBrightness);
	}
	else									//	wraps
	{
		for (int n=aStart;n<numLEDs;n++)
			tLEDs[n].setAttributes(aColor,aBrightness);
		for (int n=0;n<=aEnd;n++)
			tLEDs[n].setAttributes(aColor,aBrightness);
	}
}

void Thing::update()
{
	
}

void Thing::checkForUpdate()
{
	periodCounter++;
	
	if (canUpdate())
	{
		update();
		periodCounter = 0;
	}
}

void Thing::updateLEDs()
{
	if (io)
	{
		for (int n=0;n<32;n++)
		{
			if (!tLEDs[n].color.isBlack())
			{
				if (layer > leds[n].layer)
				{
					leds[n].setAttributes(tLEDs[n].color,brightness);
					leds[n].layer = layer;
				}
				else if (layer == leds[n].layer)
				{
					tLEDs->brightness = brightness;
					leds[n].mixWith(tLEDs[n]);
					leds[n].adjustColor();
				}
			}
		}
	}
}

void Thing::clear()
{
	setBlock(LITColor.black, maxBrightness, 0, numLEDs-1);
}


void Thing::move(bool direction)
{
	LED tmpLED;
	int maxAddress = numLEDs-1;
	
	if (direction)
	{
		tmpLED.setAttributes(tLEDs[maxAddress]);
		
		for (int n=maxAddress;n>0;n--)
			tLEDs[n].setAttributes(tLEDs[n-1]);
		
		tLEDs[0].setAttributes(tmpLED);
	}
	else
	{
		tmpLED.setAttributes(tLEDs[0]);
		
		for (int n=0;n<maxAddress;n++)
			tLEDs[n].setAttributes(tLEDs[n+1]);
		
		tLEDs[maxAddress].setAttributes(tmpLED);
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
	brightness = updateValue(brightness, direction, 0, maxBrightness, 0);
}

void Thing::fade(bool direction, byte units)
{
	if		(units < 0)					units = 0;
	while	(units > maxBrightness)		units -= maxBrightness;
	
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

bool Thing::canUpdate()
{
	if (periodCounter == period)	return 1;
	else							return 0;
}


































