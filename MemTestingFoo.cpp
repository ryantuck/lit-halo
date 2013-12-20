//	########################################################################

//  MemTestingFoo.cpp

//	8/20/13

//	########################################################################

#include "MemTestingFoo.h"

MemTestingFoo::MemTestingFoo()
{
	addLEDs(LITColor.green, maxBrightness, 0, 31);
	
	for (int n=0;n<16;n++)
	{
		Foo* aFoo = new Foo;
		addFoo(aFoo);
		
		Step<MovingFoo>* aStep = new Step<MovingFoo>;
		aStep->fnPtr = &MovingFoo::moveLeft;
		addStep(aStep);
	}
}