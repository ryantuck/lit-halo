//	########################################################################

//  BandMeterFoo.cpp

//	10/9/13

//	########################################################################

#include "BandMeterFoo.h"

BandMeterFoo::BandMeterFoo()
{
	band = 1;
	bandColor.setColor(LITColor.green);
	
	Step<BandMeterFoo>* aStep = new Step<BandMeterFoo>;
	aStep->fnPtr = &BandMeterFoo::drawLine;
	addStep(aStep);
}

BandMeterFoo::BandMeterFoo(int aBand, Color aColor)
{
	band = aBand;
	bandColor.setColor(aColor);
	
	Step<BandMeterFoo>* aStep = new Step<BandMeterFoo>;
	aStep->fnPtr = &BandMeterFoo::drawLine;
	addStep(aStep);
}

void BandMeterFoo::drawLine()
{
	float specVal = audio.eq.spectrum[band];
	
	float ratio = 32 * specVal / 128;
	
	fLEDs.removeAllEntries();
	
	addLEDs(bandColor, maxBrightness, 0, ratio);
}