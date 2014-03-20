//	########################################################################

//  Strobe.cpp

//	3/10/14

//	########################################################################

#include "Strobe.h"

Strobe::Strobe()
{
	addLEDs(LITColor.white, maxBrightness, 0, 31);
	
	strobePeriod = 2;
	colorCounter = 0;
	
	addStepWithFunction(&Strobe::flashOn, strobePeriod, 1);
	addStepWithFunction(&Strobe::flashOff, strobePeriod, 1);
}

void Strobe::flashOn()
{
	colorCounter++;
	if (colorCounter == 32) colorCounter = 0;
	
	for (int n=0;n<32;n++)
	{
		fLEDs.entry(n)->me->color.calculateRGB(32, colorCounter);
	}
}

void Strobe::flashOff()
{
	for (int n=0;n<32;n++)
	{
		fLEDs.entry(n)->me->color.setColor(LITColor.black);
	}
}


