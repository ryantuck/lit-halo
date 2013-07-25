//	########################################################################

//  SingleRunDot.cpp

//	7/23/13

//	########################################################################

#include "SingleRunDot.h"

SingleRunDot::SingleRunDot()
{
	clear();
	currentAddress = 0;
	setBlock(LITColor.green,
			 maxBrightness,
			 currentAddress,
			 currentAddress);
}

SingleRunDot::SingleRunDot(Color aColor)
{
	clear();
	currentAddress = 0;
	setBlock(aColor,
			 maxBrightness,
			 currentAddress,
			 currentAddress);
}

void SingleRunDot::update()
{
	if (currentAddress < 32)
	{
		currentAddress++;
		move(1);
	}
	else
	{
		readyToDie = 1;
	}
}

