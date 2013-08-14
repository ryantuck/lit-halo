//	########################################################################

//  Foo2.cpp

//	7/30/13

//	########################################################################

#include "Foo2.h"

Foo2::Foo2()
{
//	setBlock(LITColor.green, maxBrightness, 4, 10);
//	
//	addItem();
//	foos[0]->setBlock(LITColor.lavender, maxBrightness, 15, 18);
//	
//	foos[0]->addItem();
//	foos[0]->foos[0]->setBlock(LITColor.babyBlue, maxBrightness, 22, 29);
//	
//	direction = 1;
//	foos[0]->direction = 0;
//	foos[0]->foos[0]->direction = 1;
//	
//	period = 2;
//	foos[0]->period = 4;
//	foos[0]->foos[0]->period = 8;
	
	addLEDs(LITColor.green, maxBrightness, 4, 10);
	
	Foo* aFoo = new Foo;
	Foo* bFoo = new Foo;
	
	addFoo(aFoo);
	aFoo->addFoo(bFoo);
	
	aFoo->addLEDs(LITColor.lavender, maxBrightness, 15, 18);
	bFoo->addLEDs(LITColor.babyBlue, maxBrightness, 22, 29);
	
	direction		= 1;
	aFoo->direction = 0;
	bFoo->direction = 1;
	
	period			= 2;
	aFoo->period	= 4;
	bFoo->period	= 8;
	
	Step<Foo2>* aStep = new Step<Foo2>;
	Step<Foo2>* bStep = new Step<Foo2>;
	
	aStep->fnPtr = &Foo2::moveRight;
	bStep->fnPtr = &Foo2::moveLeft;
	
	aFoo->addStep(aStep);
	bFoo->addStep(bStep);
	
	aStep->period = 4;
	bStep->period = 8;
}

void Foo2::moveLeft()
{
	move(0);
}

void Foo2::moveRight()
{
	move(1);
}
