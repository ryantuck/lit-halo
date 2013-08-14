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
	
	Step<LinkedFoo>* aStep = new Step<LinkedFoo>;
	Step<LinkedFoo>* bStep = new Step<LinkedFoo>;
	Step<LinkedFoo>* cStep = new Step<LinkedFoo>;
	
	aStep->fnPtr = &LinkedFoo::moveRight;
	bStep->fnPtr = &LinkedFoo::moveLeft;
	cStep->fnPtr = &LinkedFoo::moveRight;
	
	addStep(aStep);
	bFoo->addStep(bStep);
	cFoo->addStep(cStep);
	
}

void LinkedFoo::moveLeft()
{
	move(1);
}

void LinkedFoo::moveRight()
{
	move(0);
}