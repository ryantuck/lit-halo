//	########################################################################

//  BrightnessFrequency.cpp

//	11/24/13

//	########################################################################

#include "BrightnessFrequency.h"

BrightnessFrequency::BrightnessFrequency()
{
	band = 2;
	start = 0;
	
	for (int n=0;n<8;n++)
	{
		addLEDs(LITColor.green, maxBrightness, 4*n+start, 4*n+start);
	}
	
	addStepWithFunction(&BrightnessFrequency::listenUp, 1);
}

BrightnessFrequency::BrightnessFrequency(int aBand,Color aColor,int aStart)
{
	band = aBand;
	start = aStart;
	
	for (int n=0;n<8;n++)
	{
		addLEDs(aColor, maxBrightness, 4*n+start, 4*n+start);
	}
	
	addStepWithFunction(&BrightnessFrequency::listenUp, 1);
	
}

void BrightnessFrequency::listenUp()
{
	float val = (float)audio.eq.spectrum[band];
	
	float max = 1024;
	
	float pct = val/max;
	
	float br = pct*200;		// note no checking here - just testing
	
	for (int n=0;n<countLEDs();n++)
	{
		fLEDs.entry(n)->me->brightness = br;
	}
}

BF4::BF4()
{
	BrightnessFrequency* bf2 = new BrightnessFrequency(2,LITColor.red,0);
	BrightnessFrequency* bf3 = new BrightnessFrequency(3,LITColor.yellow,1);
	BrightnessFrequency* bf4 = new BrightnessFrequency(4,LITColor.green,2);
	BrightnessFrequency* bf5 = new BrightnessFrequency(5,LITColor.cyan,3);
	
	addFoo(bf2);
	addFoo(bf3);
	addFoo(bf4);
	addFoo(bf5);
}