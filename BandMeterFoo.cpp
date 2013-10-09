//	########################################################################

//  BandMeterFoo.cpp

//	10/9/13

//	########################################################################

#include "BandMeterFoo.h"

BandMeterFoo::BandMeterFoo()
{
	band = 4;
	
	Step<BandMeterFoo>* aStep = new Step<BandMeterFoo>;
	aStep->fnPtr = &BandMeterFoo::drawLine;
	addStep(aStep);
}

void BandMeterFoo::drawLine()
{
	float specVal = audio.eq.spectrum[band];
	
	float ratio = 32 * specVal / 1024;
	
	fLEDs.removeAllEntries();
	
	addLEDs(LITColor.green, maxBrightness, 0, ratio);
}