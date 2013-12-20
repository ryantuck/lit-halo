//	########################################################################

//  OscillatingFoo.cpp

//	8/7/13

//	########################################################################

#include "OscillatingFoo.h"

OscillatingFoo::OscillatingFoo()
{	
	MovingFoo* aFoo = new MovingFoo;
	aFoo->addLEDs(LITColor.babyBlue, maxBrightness, 0, 0);
	aFoo->direction = 1;
	
	Step<MovingFoo>* aStep = new Step<MovingFoo>;
	aStep->fnPtr = &MovingFoo::move;
	aStep->period = 8;
	
	aFoo->addStep(aStep);
	addFoo(aFoo);
	
	Step<OscillatingFoo>* myStep = new Step<OscillatingFoo>;
	myStep->fnPtr = &OscillatingFoo::changeSpeed;
	addStep(myStep);
}

void OscillatingFoo::changeSpeed()
{
	MovingFoo* theFoo = (MovingFoo*)foos.entry(0)->me;
	Step<MovingFoo>* theStep = (Step<MovingFoo>*)theFoo->steps.entry(0)->me;
	
	int addr = theFoo->fLEDs.entry(0)->me->address;
	
	if (addr < 16)
	{
		theStep->period = 4 - addr/4;
	}
	else if (addr > 15)
	{
		theStep->period = addr/4 - 3;
	}
	
	if (addr ==	0  && theFoo->direction == 0) theFoo->direction = 1;
	if (addr == 31 && theFoo->direction == 1) theFoo->direction = 0;
}

