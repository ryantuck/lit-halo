//	########################################################################

//  Beats.cpp

//	3/2/14

//	########################################################################

#include "Beats.h"

Beats::Beats()
{
	for (int n=0;n<NUMPOINTS; n++)
	{
		points[n] = 0;
	}
	
	pointLength		= 0;
	derivativeLimit = 60;
}

bool Beats::detected()
{
	bool beatDetected = false;
	
	if (	currentValue() > midPoint()
		&&	lastValue() < midPoint()
		&&	currentDerivative() > derivativeMidPoint()
		&&	currentDerivative() > derivativeLimit)
	{
		beatDetected = true;
	}
	
	return beatDetected;
}

byte Beats::currentValue()
{
	return points[0];
}

byte Beats::lastValue()
{
	return points[1];
}

byte Beats::currentDerivative()
{
	int change = points[0] - points[1];
	
	if (change < 0)
		change = 0;
	
	return change;
}

void Beats::addPoint(int newPoint)
{
	if (pointLength < NUMPOINTS)
	{
		pointLength++;
	}
	
	for(int i = pointLength-1; i >= 1; i--)
    {
        points[i] = points[i-1];
    }
	
    points[0] = newPoint;
}

byte Beats::midPoint()
{
	byte min = points[0];
	byte max = points[0];
	
	for (int n=0;n<pointLength;n++)
	{
		if (points[n] < min)
		{
			min = points[n];
		}
		
		if (points[n] > max)
		{
			max = points[n];
		}
	}
	
	return (max-min)/2;
}

byte Beats::derivativeMidPoint()
{
	// since we're setting any negative derivatives to 0, this isn't
	// really a midpoint.
	
	byte maxDiff = 0;
	
	for (int n=0;n<pointLength-1;n++)
	{
		int tmpDiff = points[n+1] - points[n];
		
		if (tmpDiff > maxDiff)
		{
			maxDiff = tmpDiff;
		}
	}
	
	return maxDiff/2;
}




