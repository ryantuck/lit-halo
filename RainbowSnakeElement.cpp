//	####################################################################

//	RainbowSnakeElement.cpp

//	####################################################################


#include "RainbowSnakeElement.h"

RainbowSnakeElement::RainbowSnakeElement()
{
	createSegmentsArray(6);
	
	Segment* red		= new Segment;
	Segment* yellow		= new Segment;
	Segment* green		= new Segment;
	Segment* cyan		= new Segment;
	Segment* blue		= new Segment;
	Segment* magenta	= new Segment;
	
	red		->	color.setColor(1,0,0);
	yellow	->	color.setColor(1,1,0);
	green	->	color.setColor(0,1,0);
	cyan	->	color.setColor(0,1,1);
	blue	->	color.setColor(0,0,1);
	magenta	->	color.setColor(1,0,1);
	
	red		->	length	= 1;
	yellow	->	length	= 1;
	green	->	length	= 1;
	cyan	->	length	= 1;
	blue	->	length	= 1;
	magenta	->	length	= 1;
	
	red		->	start	= 5;
	yellow	->	start	= 4;
	green	->	start	= 3;
	cyan	->	start	= 2;
	blue	->	start	= 1;
	magenta	->	start	= 0;
	
	segments[0] = red;
	segments[1] = yellow;
	segments[2] = green;
	segments[3] = cyan;
	segments[4] = blue;
	segments[5] = magenta;
}