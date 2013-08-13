//	########################################################################

//  Foo1.cpp

//	7/30/13

//	########################################################################

#include "Foo1.h"


Foo1::Foo1()
{
//	setBlock(LITColor.red, maxBrightness, 2, 5);
//	setBlock(LITColor.orange, maxBrightness, 6, 8);
//	
//	addItem();
//	
//	foos[0]->setBlock(LITColor.blue, maxBrightness, 19, 24);
//	
//	direction = 0;
//	
//	foos[0]->direction = 1;
	
	addLEDs(LITColor.red, maxBrightness, 2, 5);
	addLEDs(LITColor.orange, maxBrightness, 6,8);
	
	Foo* aFoo = new Foo;
	aFoo->addLEDs(LITColor.blue, maxBrightness, 19, 24);
	addFoo(aFoo);
	
	aFoo->direction = 1;
	aFoo->layer		= 2;
}
