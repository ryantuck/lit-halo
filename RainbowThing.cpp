//	########################################################################

//  RainbowThing.cpp

//	7/23/13

//	########################################################################

#include "RainbowThing.h"

RainbowThing::RainbowThing()
{
	setBlock(LITColor.black, maxBrightness, 0, 31);
	
	for (int n=0;n<12;n++)
	{
		setBlock(*LITColor.spectrum[n], maxBrightness, n, n);
	}
}

RainbowThing::RainbowThing(int start)
{
	setBlock(LITColor.black, maxBrightness, 0, 31);
	
	for (int n=0;n<12;n++)
	{
		setBlock(*LITColor.spectrum[n], maxBrightness, n+start, n+start);
	}
	
}

void RainbowThing::update()
{
	move(0);
}