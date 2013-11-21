//	########################################################################

//  LITFunctions.cpp

//	8/28/13

//	########################################################################

#include "LITFunctions.h"

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

extern Color SRColor(int srIndex)
{
	// changes the order of r,g,b values based on
	// the LED's index due to varied SR pin assignments
	
	// ** need to check index for bounds
	
	Color aColor(LITColor.black);
	
	int sR = 0;
	int sG = 0;
	int sB = 0;
	
	int base	= srIndex / 8;
	int rem		= srIndex % 8;
	base		= base*8;
	
	if (rem < 3)		// 0-2
	{
		int var = 5 % (rem+3);
		int var2 = (rem-var+3) % 3;
		
		//	n	v	v2
		//	0	2	1
		//	1	1	0
		//	2	0	2
		
		sR = leds[base+var].color.g;
		sG = leds[base+var].color.r;
		sB = leds[base+var2].color.b;
	}
	else if (rem < 5)	// 3-4
	{
		int var = 4 % rem;
		
		sR = leds[base+4+var].color.r;
		sG = leds[base+3+var].color.b;
		sB = leds[base+3+var].color.g;
	}
	else if (rem < 6)	// 5
	{
		sR = leds[base+3].color.r;
		sG = leds[base+5].color.g;
		sB = leds[base+5].color.b;
	}
	else if (rem < 8)	// 6-7
	{
		int var = 7 % rem;
		
		sR = leds[base+6+var].color.b;
		sG = leds[base+6+var].color.g;
		sB = leds[base+6+var].color.r;
	}
	
	aColor.setColor(sR,sG,sB);
	return aColor;
}

int runningAverage(int avg, int sample, int numDataPoints)
{
	int diff = sample - avg;
	avg += diff / numDataPoints;
	return avg;
}


int yOfLine(int m, int b, int x)
{
	return m*x + b;
}












