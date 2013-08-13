//	########################################################################

//  OscillatingFoo.cpp

//	8/7/13

//	########################################################################

#include "OscillatingFoo.h"

OscillatingFoo::OscillatingFoo()
{
	Foo* aFoo = new Foo;
	aFoo->addLEDs(LITColor.babyBlue, maxBrightness, 0, 0);
	aFoo->direction = 1;
	aFoo->period	= 8;
	addFoo(aFoo);
}

void OscillatingFoo::update()
{
	int addr = myFooList.entry(0)->me->myLEDList.entry(0)->me->address;
	
	if (addr < 16)
	{
		myFooList.entry(0)->me->period = 4 - addr/4;
	}
	else if (addr > 15)
	{
		myFooList.entry(0)->me->period = addr/4 - 3;
	}
	
	if (addr == 0 && myFooList.entry(0)->me->direction == 0)
		myFooList.entry(0)->me->direction = 1;
	if (addr == 31 && myFooList.entry(0)->me->direction == 1)
		myFooList.entry(0)->me->direction = 0;
}

