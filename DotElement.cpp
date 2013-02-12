//	####################################################################

//	DotElement.cpp

//	####################################################################


#include "DotElement.h"

DotElement::DotElement()
{
	createSegments(1);
	
	segments[0]->color.setColor(1,69,100);
	segments[0]->length	= 1;
	segments[0]->start	= 0;
	
	layer		= 1;
	rate		= 3;
	brightness	= 100;
	io			= 1;

}