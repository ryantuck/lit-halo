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
	
	aFoo->direction = 0;
	bFoo->direction = 1;
	
	addFoo(aFoo);
	addFoo(bFoo);
}

