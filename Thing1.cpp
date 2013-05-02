//	########################################################################

//  Thing1.cpp

//	4/23/13

//	########################################################################

#include "Thing1.h"


Thing1::Thing1()
{
	Color red	= Color(1,0,0);
	Color blue	= Color(0,0,1);
	Color green	= Color(0,1,0);
	Color off	= Color(0,0,0);
	
	setBlock(off, 0, 0, 15);
	
	setBlock(red, 100, 0, 5);
	setBlock(green, 50, 6, 9);
	setBlock(blue, 75, 12, 15);
}


void Thing1::update()
{
	move(0, 1);
}