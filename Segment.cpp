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
	Serial.print("1 length: "); Serial.print(newLength);
	
	newLength	= checkVal(newLength, 1, 16, 0);
	newStart	= checkVal(newStart,  0, 15, 1);
	
	Serial.print("2 length: "); Serial.print(newLength);
	
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