//	########################################################################

//  ListenerFoo.cpp

//	8/22/13

//	########################################################################

#include "ListenerFoo.h"

ListenerFoo::ListenerFoo()
{
	Step<ListenerFoo>* aStep = new Step<ListenerFoo>;
	aStep->fnPtr = &ListenerFoo::listen;
	addStep(aStep);
}

void ListenerFoo::listen()
{	
	if (audio.beatJustDetected(0))
	{
		MovingDot* a = new MovingDot;
		addFoo(a);
	}
}

MovingDot::MovingDot()
{
	addLEDs(LITColor.green, maxBrightness, 0, 0);
	
	Step<MovingFoo>* aStep = new Step<MovingFoo>;
	aStep->fnPtr = &MovingFoo::move;
	aStep->count = 32;
	addStep(aStep);
	
	repeats = false;
}