//	########################################################################

//  StillFoos.cpp

//	1/7/14

//	########################################################################

#include "StillFoos.h"

StillRainbow::StillRainbow(int aBrightness)
{
	// rather redundant
	
	RainbowLine* x = new RainbowLine(32,0);
	addFoo(x);
	
	for (int n=0;n<32;n++)
	{
		x->fLEDs.entry(n)->me->brightness = aBrightness;
	}
}

StillDoubleRainbow::StillDoubleRainbow(int aBrightness)
{
	RainbowLine* x = new RainbowLine(16,0);
	RainbowLine* y = new RainbowLine(16,16);
	addFoo(x);
	addFoo(y);
	
	for (int n=0;n<16;n++)
	{
		x->fLEDs.entry(n)->me->brightness = aBrightness;
		y->fLEDs.entry(n)->me->brightness = aBrightness;
	}
}

StillEvenlySpaced::StillEvenlySpaced(int aBrightness, Color aColor, int aNumber, int aStart)
{
	// no error checking implemented here yet
	// should take in 1,2,4,8,16,32
	
	int interval = 32 / aNumber;
	
	for (int n=0;n<aNumber;n++)
	{
		int addr = checkAddress(aStart + interval*n);
		
		addLEDs(aColor, aBrightness, addr, addr);
	}
}

StillDubz::StillDubz(int aBrightness)
{
	Foo* x = new StillEvenlySpaced(aBrightness, LITColor.green, 8, 0);
	Foo* y = new StillEvenlySpaced(aBrightness, LITColor.magenta, 8, 2);
	addFoo(x);
	addFoo(y);
}











