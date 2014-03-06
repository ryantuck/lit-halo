//	########################################################################

//  BandMeterFoo.cpp

//	10/9/13

//	########################################################################

#include "BandMeterFoo.h"

BandMeterFoo::BandMeterFoo()
{
	band = 1;
	bandColor.setColor(LITColor.green);
	denominator = 1024;
	
	Step<BandMeterFoo>* aStep = new Step<BandMeterFoo>;
	aStep->fnPtr = &BandMeterFoo::drawLine;
	addStep(aStep);
}

BandMeterFoo::BandMeterFoo(int aBand, Color aColor)
{
	band = aBand;
	bandColor.setColor(aColor);
	denominator = 1024;
	
	Step<BandMeterFoo>* aStep = new Step<BandMeterFoo>;
	aStep->fnPtr = &BandMeterFoo::drawLine;
	addStep(aStep);
}

BandMeterFoo::BandMeterFoo(int aBand, Color aColor, int aDenominator)
{
	band = aBand;
	bandColor.setColor(aColor);
	denominator = aDenominator;
	
	Step<BandMeterFoo>* aStep = new Step<BandMeterFoo>;
	aStep->fnPtr = &BandMeterFoo::drawLine;
	addStep(aStep);

}

void BandMeterFoo::drawLine()
{
	float specVal = audio.eq.spectrum[band];
	
	float ratio = 32 * specVal / denominator;
	
	fLEDs.removeAllEntries();
	
	addLEDs(bandColor, maxBrightness, 0, ratio);
}


// ================================================================

MeterWithFlash::MeterWithFlash(int aBand, Color aColor)
{
	BandMeterFoo* x = new BandMeterFoo(aBand, aColor);
	addFoo(x);
	
	band = aBand;
	
	addStepWithFunction(&MeterWithFlash::listen, 1);
}

void MeterWithFlash::listen()
{
	if (audio.beats.detected())
	{
		DotFlash* a = new DotFlash(10);
		addFoo(a);
	}
}

DotFlash::DotFlash(int addr)
{
	repeats = false;
	
	addLEDs(LITColor.white, maxBrightness, addr, addr);
	
	addStepWithFunction(&DotFlash::shine, 1, 6);
}

void DotFlash::shine()
{
	
}



