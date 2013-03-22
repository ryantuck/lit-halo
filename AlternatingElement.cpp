//	####################################################################

//	AlternatingElement.cpp

//	####################################################################


#include "AlternatingElement.h"

AlternatingElement::AlternatingElement()
{
	clearSegments();
	createSegmentsArray(8);
	
	layer		= 1;
	rate		= 1;
	brightness	= 127;
	io			= 1;
    
	for (int n=0;n<maxSegments;n++)
		segments[n] = new Segment(LITColor.red,1,2*n);
}

AlternatingElement::AlternatingElement(Color newColor,bool odds)
{
	clearSegments();
	createSegmentsArray(8);
	
	layer		= 1;
	rate		= 1;
	brightness	= 100;
	io			= 1;
	
	int tmpStart = 0;
	if (odds)	tmpStart = 1;
	
	for (int n=0;n<maxSegments;n++)
		segments[n] = new Segment(LITColor.red,1,tmpStart + 2*n);
}
