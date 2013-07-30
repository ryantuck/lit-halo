//	########################################################################

//  FooThing.cpp

//	7/29/13

//	########################################################################

#include "FooThing.h"

FooThing::FooThing()
{
	clear();
	
	aFoo.setBlock(LITColor.orange, maxBrightness, 13, 19);
	aFoo.setBlock(LITColor.red, maxBrightness, 1, 4);
	
	aFoo.addItem();
	aFoo.addItem();
	aFoo.addItem();
	aFoo.addItem();
	aFoo.addItem();
	aFoo.addItem();
	
	aFoo.foos[0]->setBlock(LITColor.green, maxBrightness, 6, 9);
	aFoo.foos[1]->setBlock(LITColor.yellow, maxBrightness, 22, 27);
	
	aFoo.foos[0]->addItem();
	
	aFoo.foos[0]->foos[0]->setBlock(LITColor.blue, maxBrightness, 29, 31);
	
	aFoo.foos[0]->buttplug = 1;
	aFoo.foos[0]->foos[0]->buttplug = 1;
	
	aFoo.period = 4;
	
	aFoo.foos[0]->period = 10;
	aFoo.foos[1]->period = 2;
}


void FooThing::update()
{
	aFoo.update();
}
