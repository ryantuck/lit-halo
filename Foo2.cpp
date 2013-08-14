//	########################################################################

//  Foo2.cpp

//	7/30/13

//	########################################################################

#include "Foo2.h"

Foo2::Foo2()
{	
	addLEDs(LITColor.green, maxBrightness, 4, 10);
	
	Foo* aFoo = new Foo;
	Foo* bFoo = new Foo;
	
	addFoo(aFoo);
	aFoo->addFoo(bFoo);
	
	aFoo->addLEDs(LITColor.lavender, maxBrightness, 15, 18);
	bFoo->addLEDs(LITColor.babyBlue, maxBrightness, 22, 29);
	
	Step<Foo2>* aStep = new Step<Foo2>;
	Step<Foo2>* bStep = new Step<Foo2>;
	
	aStep->fnPtr = &MovingFoo::moveRight;
	bStep->fnPtr = &MovingFoo::moveLeft;
	
	aFoo->addStep(aStep);
	bFoo->addStep(bStep);
	
	aStep->period = 4;
	bStep->period = 8;
}

