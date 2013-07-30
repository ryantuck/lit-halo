//	########################################################################

//  Foo2.cpp

//	7/30/13

//	########################################################################

#include "Foo2.h"

Foo2::Foo2()
{
	setBlock(LITColor.green, maxBrightness, 4, 10);
	
	addItem();
	foos[0]->setBlock(LITColor.lavender, maxBrightness, 15, 18);
	
	foos[0]->addItem();
	foos[0]->foos[0]->setBlock(LITColor.babyBlue, maxBrightness, 22, 29);
	
	buttplug = 1;
	foos[0]->buttplug = 0;
	foos[0]->foos[0]->buttplug = 1;
	
	period = 2;
	foos[0]->period = 4;
	foos[0]->foos[0]->period = 8;
}

