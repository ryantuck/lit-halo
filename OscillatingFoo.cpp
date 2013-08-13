//	########################################################################

//  OscillatingFoo.cpp

//	8/7/13

//	########################################################################

#include "OscillatingFoo.h"

OscillatingFoo::OscillatingFoo()
{
	addItem();
	foos[0]->setBlock(LITColor.babyBlue, maxBrightness, 0, 0);
	foos[0]->direction	= 1;
	foos[0]->period		= 8;
}

void OscillatingFoo::update()
{
	int addr = foos[0]->fLEDs[0]->address;
	
	if (addr < 16)
	{
		foos[0]->period = 4 - addr/4;
	}
	else if (addr > 15)
	{
		foos[0]->period = addr/4 - 3;
	}
	
	if (addr == 0 && foos[0]->direction == 0)	foos[0]->direction = 1;
	if (addr == 31 && foos[0]->direction == 1)	foos[0]->direction = 0;
}

