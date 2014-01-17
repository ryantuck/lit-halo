//	########################################################################

//  BandMeterFoo.cpp

//	10/9/13

//	########################################################################

#include "BandMeterFoo.h"

BandMeterFoo::BandMeterFoo()
{
    denominator = 1024;
	
	Step<BandMeterFoo>* aStep = new Step<BandMeterFoo>;
	aStep->fnPtr = &BandMeterFoo::drawLine;
	addStep(aStep);
}

//BandMeterFoo::BandMeterFoo(int aBand, Color aColor)
//{
//	band = aBand;
//	bandColor.setColor(aColor);
//	denominator = 1024;
//
//	Step<BandMeterFoo>* aStep = new Step<BandMeterFoo>;
//	aStep->fnPtr = &BandMeterFoo::drawLine;
//	addStep(aStep);
//}

//BandMeterFoo::BandMeterFoo(int aBand, Color aColor, int aDenominator)
//{
//	band = aBand;
//	bandColor.setColor(aColor);
//	denominator = aDenominator;
//
//	Step<BandMeterFoo>* aStep = new Step<BandMeterFoo>;
//	aStep->fnPtr = &BandMeterFoo::drawLine;
//	addStep(aStep);
//
//}

void BandMeterFoo::drawLine()
{
    //	float specVal = audio.eq.spectrum[band];
    //
    //
    //	float ratio = 32 * specVal / denominator;
	fLEDs.removeAllEntries();
    for(int n = 0; n < 6; n++)
    {
        if(audio.beatDetected[n])
        {
            Serial.println("beat detected");
            switch(n)
            {
                case 0:
                    bandColor.setColor(LITColor.magenta);
                    break;
                case 1:
                    bandColor.setColor(LITColor.blue);
                    break;
                case 2:
                    bandColor.setColor(LITColor.green);
                    break;
                case 3:
                    bandColor.setColor(LITColor.yellow);
                    break;
                case 4:
                    bandColor.setColor(LITColor.orange);
                    break;
                case 5:
                    bandColor.setColor(LITColor.red);
                    break;
                default:
                    bandColor.setColor(LITColor.white);
                    break;
            }
            addLEDs(bandColor, maxBrightness, 0, 32);
            break;
        }
    }
}