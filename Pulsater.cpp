//	########################################################################

//  Pulsater.cpp

//	1/23/14

//	########################################################################

#include "Pulsater.h"

Pulsater::Pulsater()
{
	for (int n=0;n<8;n++)
	{
		addLEDs(LITColor.white, 0, 4*n, 4*n);
	}
	
	Step<Pulsater>* upStep = new Step<Pulsater>;
	upStep->fnPtr = &Pulsater::upBrightness;
	upStep->count = 100;
	addStep(upStep);
	
	Step<Pulsater>* downStep = new Step<Pulsater>;
	downStep->fnPtr = &Pulsater::downBrightness;
	downStep->count = 100;
	addStep(downStep);
}

void Pulsater::upBrightness()
{
	for (int n=0;n<countLEDs();n++)
	{
		byte x = fLEDs.entry(n)->me->brightness;
		x = updateValue(x, up, 0, maxBrightness, !cycles);
		fLEDs.entry(n)->me->brightness = x;
	}
}

void Pulsater::downBrightness()
{
	for (int n=0;n<countLEDs();n++)
	{
		byte x = fLEDs.entry(n)->me->brightness;
		x = updateValue(x, down, 0, maxBrightness, !cycles);
		fLEDs.entry(n)->me->brightness = x;
	}
}


