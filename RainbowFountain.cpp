//	########################################################################

//  RainbowFountain.cpp

//	1/31/14

//	########################################################################

#include "RainbowFountain.h"

RainbowFountain::RainbowFountain(bool aDirection)
{
	cIndex		= 0;
	direction	= aDirection;
	addStepWithFunction(&RainbowFountain::iterate, 2);
}

void RainbowFountain::iterate()
{
	// create two moving dots and set them in motion
	
	// set whether they emanate from the front or back of hb
	bool dir1 = up;
	bool dir2 = down;
	int addr1 = 0;
	int addr2 = numLEDs-1;
	
	if (direction)
	{
		dir1	= !dir1;
		dir2	= !dir2;
		addr1	= numLEDs/2;
		addr2	= numLEDs/2 - 1;
	}
	
	MovingDot* a = new MovingDot(*LITColor.colorList[cIndex],dir1,addr1);
	MovingDot* b = new MovingDot(*LITColor.colorList[cIndex],dir2,addr2);
	addFoo(a);
	addFoo(b);
	
	// make finite
	a->repeats = false;
	b->repeats = false;
	
	a->steps.entry(0)->me->count = numLEDs/2 - 1;
	b->steps.entry(0)->me->count = numLEDs/2 - 1;
	
	a->steps.entry(0)->me->period = 2;
	b->steps.entry(0)->me->period = 2;
	
	// cycle color index
	cIndex = updateValue(cIndex, up, 0, 5, cycles);
}


