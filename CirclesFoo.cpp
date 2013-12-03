//	########################################################################

//  CirclesFoo.cpp

//	8/21/13

//	########################################################################

#include "CirclesFoo.h"

CirclesFoo::CirclesFoo()
{
	for (int n=0;n<12;n++)
	{
		MovingFoo* aFoo = new MovingFoo;
		aFoo->addLEDs(*LITColor.spectrum[n], maxBrightness, 0, 0);
		aFoo->direction = 1;
		
		Step<MovingFoo>* aStep = new Step<MovingFoo>;
		aStep->fnPtr = &MovingFoo::move;
		aStep->period = n;
		
		aFoo->addStep(aStep);
		addFoo(aFoo);
	}
}