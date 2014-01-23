//	########################################################################

//  EventFoo.cpp

//	7/30/13

//	########################################################################

#include "EventFoo.h"

EventFoo::EventFoo()
{
	killCounter = 0;

	Foo* aFoo = new Foo;
	addFoo(aFoo);
	aFoo->addLEDs(LITColor.red, maxBrightness, 2, 5);
	
	Step<EventFoo>* aStep = new Step<EventFoo>;
	
	aStep->fnPtr = &EventFoo::moveLeft;
	aFoo->addStep(aStep);
	
	aStep->count = 50;
	
	aFoo->repeats = false;
}

