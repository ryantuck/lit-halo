//	########################################################################

//  StillFoos.cpp

//	1/7/14

//	########################################################################

#include "StillFoos.h"

StillRainbow::StillRainbow()
{
	// rather redundant
	
	RainbowLine* x = new RainbowLine(32,0);
	addFoo(x);
}

StillDoubleRainbow::StillDoubleRainbow()
{
	RainbowLine* x = new RainbowLine(16,0);
	RainbowLine* y = new RainbowLine(16,16);
	addFoo(x);
	addFoo(y);
}

StillEvenlySpaced::StillEvenlySpaced(Color aColor, int aNumber, int aStart)
{
	// no error checking implemented here yet
	// should take in 1,2,4,8,16,32
	
	int interval = 32 / aNumber;
	
	for (int n=0;n<aNumber;n++)
	{
		int addr = checkAddress(aStart + interval*n);
		
		addLEDs(aColor, maxBrightness, addr, addr);
	}
}

StillDubz::StillDubz()
{
	Foo* x = new StillEvenlySpaced(LITColor.green, 8, 0);
	Foo* y = new StillEvenlySpaced(LITColor.magenta, 8, 2);
	addFoo(x);
	addFoo(y);
}











