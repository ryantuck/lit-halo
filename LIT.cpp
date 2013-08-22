//	########################################################################

//  LIT.cpp

//	5/2/13

//	########################################################################

#include "LIT.h"

int			numLEDs = 32;
LayeredLED	leds[32];
Audio		audio;

extern byte updateValue(byte parameter,
						bool direction,
						byte minVal,
						byte maxVal,
						bool doesCycle)
{
	if (direction)
	{
		if (parameter == maxVal)
		{
			if (doesCycle)	parameter = minVal;
			else			parameter = maxVal;
		}
		else parameter++;
	}
	else
	{
		if (parameter == minVal)
		{
			if (doesCycle)	parameter = maxVal;
			else			parameter = minVal;
		}
		else parameter--;
	}
	
	return parameter;
}

extern byte shortDistance(byte x, byte y)
{
	int difference = x-y;
	
	if (difference < 0) difference += 32;
	
	if (difference <= 15)	return difference;
	else					return 32 - difference;
}

extern byte longDistance(byte x, byte y)
{
	return 32 - shortDistance(x, y);
}

extern bool shortDirection(byte start, byte end)
{
	int diff = end - start;
	int longDist = longDistance(start, end);
	
	if (diff > 0)
	{
		if (diff == longDist)	return 0;
		else					return 1;
	}
	else
	{
		diff = 0-diff;
		if (diff == longDist)	return 1;
		else					return 0;
	}
	
}

extern bool longDirection(byte start, byte end)
{
	return !shortDirection(start, end);
}

extern byte checkAddress(int x)
{
	while (x > 32)
	{
		x -= 32;
	}
	
	return x;
}












