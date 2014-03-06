//	########################################################################

//  Sparkle.cpp

//	1/23/14

//	########################################################################

#include "Sparkle.h"

Sparkle::Sparkle()
{
	index = 0;
	
	Serial.println("Sparkle constructor");
	for (int n=0;n<6;n++)
	{
		int x = rand()%32;
		addLEDs(LITColor.white, maxBrightness, x, x);
	}
		
	addStepWithFunction(&Sparkle::flicker,2);
}

void Sparkle::flicker()
{
	for (int n=0;n<countLEDs();n++)
	{
		fLEDs.entry(n)->me->address = rand()%32;
	}
	
	if (audio.beats.detected())
	{
		index = updateValue(index, up, 0, 6, cycles);
		
		for (int n=0;n<countLEDs();n++)
		{
			fLEDs.entry(n)->me->color.setColor(*LITColor.colorList[index]);
		}
	}
}




