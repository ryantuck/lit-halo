//	########################################################################

//  RainbowLine.cpp

//	8/22/13

//	########################################################################

#include "RainbowLine.h"

RainbowLine::RainbowLine(int length,int start)
{
	for (int n=0;n<length;n++)
	{
		Color aColor = Color(LITColor.black);
		aColor.calculateRGB(length, n);
		
		addLEDs(aColor, maxBrightness, checkAddress(start + n), checkAddress(start + n));
	}
	
//	Step<MovingFoo>* aStep = new Step<MovingFoo>;
//	aStep->fnPtr = &MovingFoo::move;
//	addStep(aStep);
}
