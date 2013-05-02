//	########################################################################

//  Thing1.cpp

//	4/23/13

//	########################################################################

#include "Thing1.h"


Thing1::Thing1()
{	
	setBlock(LITColor.black, 0, 0, 15);
	
	setBlock(LITColor.red, 100, 0, 5);
	setBlock(LITColor.green, 50, 6, 9);
	setBlock(LITColor.blue, 75, 12, 15);
}


void Thing1::update()
{
	move(0, 1);
}