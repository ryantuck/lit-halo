//	########################################################################

//  RainbowLine.cpp

//	8/22/13

//	########################################################################

#include "RainbowLine.h"

RainbowLine::RainbowLine()
{

}

RainbowLine::RainbowLine(int length,int start)
{
	for (int n=0;n<length;n++)
	{
		Color aColor = Color(LITColor.black);
		aColor.calculateRGB(length, n);
		
		addLEDs(aColor, maxBrightness, checkAddress(start + n), checkAddress(start + n));
	}
}


DoubleRainbow::DoubleRainbow()
{
	RainbowLine* r1 = new RainbowLine(16,0);
	RainbowLine* r2 = new RainbowLine(16,16);
	
	addFoo(r1);
	addFoo(r2);
}



