//	########################################################################

//  Foo3.cpp

//	7/31/13

//	########################################################################

#include "Foo3.h"

Foo3::Foo3()
{
	addItem();
	
	setBlock(LITColor.red, maxBrightness, 1, 5);
	buttplug	= 1;
	period		= 20;
	
	foos[0]->setBlock(LITColor.blue, maxBrightness, 1, 5);
	foos[0]->buttplug = 1;
	foos[0]->period = 20;
}

