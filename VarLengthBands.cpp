//	########################################################################

//  VarLengthBands.cpp

//	11/24/13

//	########################################################################

#include "VarLengthBands.h"

VarLengthBands::VarLengthBands()
{
	// add 32 LEDs
	addLEDs(LITColor.white, maxBrightness, 0, 31);
	
	Step<VarLengthBands>* myStep = new Step<VarLengthBands>;
	myStep->fnPtr = &VarLengthBands::changeLengths;
	addStep(myStep);
}

void VarLengthBands::changeLengths()
{
	int sum = audio.eq.spectrumSum();
	
	int last = 0;
	
	for (int n=0;n<7;n++)
	{
		int val = audio.eq.spectrum[n];
		
		float x = 32 * val / sum;
		
		for (int p=0;p<x;p++)
		{
			fLEDs.entry(last + p)->me->color.setColor(*LITColor.colorList[n]);
		}
		
		last += x;
	}
}