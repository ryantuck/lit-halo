//	########################################################################

//  RainbowFoo.cpp

//	7/31/13

//	########################################################################

#include "RainbowFoo.h"

RainbowFoo::RainbowFoo()
{	
	Foo* aFoo = new Foo;
	Foo* bFoo = new Foo;
	
	for (int n=0;n<12;n++)
	{
		aFoo->addLEDs(*LITColor.spectrum[n], maxBrightness, n, n);
		bFoo->addLEDs(*LITColor.spectrum[n], maxBrightness, n+16, n+16);
	}
	
	addFoo(aFoo);
	addFoo(bFoo);
	
	Step<RainbowFoo>* aStep = new Step<RainbowFoo>;
	Step<RainbowFoo>* bStep = new Step<RainbowFoo>;

	aStep->fnPtr = &RainbowFoo::moveLeft;
	bStep->fnPtr = &RainbowFoo::moveRight;
	
	aFoo->addStep(aStep);
	bFoo->addStep(bStep);
}

void RainbowFoo::moveLeft()
{
	move(1);
}

void RainbowFoo::moveRight()
{
	move(0);
}