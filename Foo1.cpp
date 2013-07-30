//	########################################################################

//  Foo1.cpp

//	7/30/13

//	########################################################################

#include "Foo1.h"


Foo1::Foo1()
{
	setBlock(LITColor.red, maxBrightness, 2, 5);
	setBlock(LITColor.orange, maxBrightness, 6, 8);
	
	addItem();
	
	foos[0]->setBlock(LITColor.blue, maxBrightness, 19, 24);
	
	buttplug = 0;
	
	foos[0]->buttplug = 1;
}
