//	########################################################################

//  LinkedFoo.cpp

//	8/13/13

//	########################################################################

#include "LinkedFoo.h"

LinkedFoo::LinkedFoo()
{
	// add LEDs to this foo
	addLEDs(LITColor.green, maxBrightness, 1, 10);
	
	//	create a foo and add it to this foo's list
	Foo* bFoo = new Foo;
	bFoo->addLEDs(LITColor.pink, maxBrightness, 13, 16);
	addFoo(bFoo);
	
	//	create another foo and add it to bFoo's foos list
	Foo* cFoo = new Foo;
	cFoo->addLEDs(LITColor.babyBlue, maxBrightness, 14, 24);
	bFoo->addFoo(cFoo);
	
	//	change parameters after adding - everything still works
	cFoo->period	= 4;
	bFoo->direction = 1;
}