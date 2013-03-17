//	####################################################################

//	DotElement.cpp

//	####################################################################


#include "DotElement.h"

DotElement::DotElement()
{
	createSegmentsArray(1);
	
	segments[0]->color.setColor(1,69,100);
	segments[0]->length	= 1;
	segments[0]->start	= 0;
	
	layer		= 1;
	rate		= 3;
	brightness	= 100;
	io			= 1;

}

DotElement::DotElement(Color myColor, int myStart)
{
	createSegmentsArray(1);
	
	segments[0]->color.setColor(myColor);
	segments[0]->length	= 1;
	segments[0]->start	= myStart;
	
	layer		= 1;
	rate		= 3;
	brightness	= 100;
	io			= 1;
}