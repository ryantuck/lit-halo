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
	if (newLength	<  1)	newLength	=  1;
	if (newLength	> 16)	newLength	= 16;
	
	if (newStart	<  0)	newStart	=  0;
	if (newStart	> 15)	newStart	= 15;
	
	color.setColor(newColor);
	length	= newLength;
	start	= newStart;
}

byte Segment::checkVal(byte parameter, byte minVal, byte maxVal, bool cycles)
{
	if (parameter == maxVal)
	{
		if (cycles) parameter = minVal;
		else		parameter = maxVal;
	}
	else if (parameter == minVal)
	{
		if (cycles) parameter = maxVal;
		else		parameter = minVal;
	}
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