//	########################################################################

//  InAndOutFader.cpp

//	1/24/14

//	########################################################################

#include "InAndOutFader.h"

InAndOutFader::InAndOutFader(Color aColor,int addr)
{
	repeats = false;
	
	addLEDs(aColor, 0, addr, addr);
	
	totalIterations = 0;
	
	Step<InAndOutFader>* a = new Step<InAndOutFader>;
	a->fnPtr = &InAndOutFader::fade;
	a->count = 100;
	addStep(a);
	
	
	
}

void InAndOutFader::getBrighter()
{
	int x = fLEDs.entry(0)->me->brightness;
	x = updateValue(x, up, 0, 100, !cycles);
	fLEDs.entry(0)->me->brightness = x;
	
}

void InAndOutFader::dimDown()
{
	int x = fLEDs.entry(0)->me->brightness;
	x--;
	fLEDs.entry(0)->me->brightness = x;
}

void InAndOutFader::fade()
{
	int x = fLEDs.entry(0)->me->brightness;
	
	if (totalIterations < 50)
	{
		x = updateValue(x, up, 0, 100, !cycles);
		x = updateValue(x, up, 0, 100, !cycles);
	}
	else
	{
		x = updateValue(x, down, 0, 100, !cycles);
		x = updateValue(x, down, 0, 100, !cycles);
	}
	
	fLEDs.entry(0)->me->brightness = x;
	
	totalIterations++;
}






