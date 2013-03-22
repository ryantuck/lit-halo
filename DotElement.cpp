//	####################################################################

//	DotElement.cpp

//	####################################################################


#include "DotElement.h"

DotElement::DotElement()
{
	
	clearSegments();
	Serial.println("dot element constructor");
	createSegmentsArray(1);
	
	segments[0] = new Segment(LITColor.red,1,0);
	
	layer		= 1;
	rate		= 3;
	brightness	= 100;
	io			= 1;

}

DotElement::DotElement(Color myColor, int myStart)
{
	clearSegments();
	createSegmentsArray(1);
	
	segments[0] = new Segment(myColor,1,myStart);
	
	layer		= 1;
	rate		= 3;
	brightness	= 100;
	io			= 1;
}