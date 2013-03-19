//	####################################################################
//
//	Segment.cpp
//
//	####################################################################

#include "Segment.h"

Segment::Segment()
{
	color.setColor(1,69,100);
	length	= 1;
	start	= 0;
}

Segment::Segment(Color newColor, byte newLength, byte newStart)
{
	length	= checkVal(newLength, 1, 16, 0);
	start	= checkVal(newStart,  0, 15, 1);

	color.setColor(newColor);
}

void Segment::check()
{
	length	= checkVal(length, 1, 16, 0);
	start	= checkVal(start,  0, 15, 1);
}

void Segment::resize(bool growing, bool direction)
{
	if (direction)
	{
		if (growing)
		{
			length++;
		}
		else
		{
			length--;
			start++;
		}
	}
	else
	{
		if (growing)
		{
			length++;
			start--;
		}
		else
		{
			length--;
		}
	}
	
	check();

}


byte Segment::checkVal(byte parameter, byte minVal, byte maxVal, bool cycles)
{
	while (parameter > maxVal)
	{
		if (cycles) parameter -= maxVal + 1;
		else		parameter = maxVal;
	}
	while (parameter < minVal)
	{
		if (cycles) parameter += maxVal + 1;
		else		parameter = minVal;
	}
	
	return parameter;
}


void Segment::printVitals()
{
	color.printVitals();
	Serial.print("Start:   ");
	if (start < 10) Serial.print(" ");
	Serial.println(start);
	Serial.print("Length:  ");
	if (length < 10) Serial.print(" ");
	Serial.println(length);
	Serial.println();
}