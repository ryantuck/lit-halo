//	########################################################################

//  Thing2.cpp

//	5/2/13

//	########################################################################

#include "Thing2.h"

Thing2::Thing2()
{
	
}

Thing2::Thing2(Color aColor, int start, int end, bool aDirection)
{
	setBlock(LITColor.black, 0, 0, 15);
	
	setBlock(aColor, 100, start, end);
	
	dir = aDirection;
}

void Thing2::update()
{
	move(dir);
}



