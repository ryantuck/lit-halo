//	####################################################################

//	AlternatingElement.cpp

//	####################################################################


#include "AlternatingElement.h"

AlternatingElement::AlternatingElement()
{
	createSegments(8);
	
	layer		= 1;
	rate		= 1;
	brightness	= 100;
	io			= 1;
	
	for (int n=0;n<maxSegments;n++)
	{
		segments[n]->length	=1;
		segments[n]->start	= 2*n;
		segments[n]->color.setColor(1,69,100);
	}
}

AlternatingElement::AlternatingElement(Color newColor,bool odds)
{
	createSegments(8);
	
	layer		= 1;
	rate		= 1;
	brightness	= 100;
	io			= 1;
	
	int tmpStart = 0;
	if (odds)	tmpStart = 1;
	
	for (int n=0;n<maxSegments;n++)
	{
		segments[n]->length	= 1;
		segments[n]->start	= tmpStart + 2*n;
		segments[n]->color.setColor(newColor);
	}
}
