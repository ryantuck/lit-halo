//	########################################################################

//  BeatCollector.cpp

//	1/24/14

//	########################################################################

#include "BeatCollector.h"

BeatCollector::BeatCollector()
{
	sampleCount = 0;
	lightCounter = 0;
	dataPoints = 100;
	
	for (int n=0;n<7;n++)
	{
		for (int m=0;m<dataPoints;m++)
		{
			specData[n][m] = 0;
		}
	}
	
	addLEDs(LITColor.red, maxBrightness, 0, 0);
	
	Serial.println("constructor works!");
	
	Step<BeatCollector>* step0 = new Step<BeatCollector>;
	step0->fnPtr = &BeatCollector::stopLight;
	step0->count = 3;
	addStep(step0);
	
	Step<BeatCollector>* stepA = new Step<BeatCollector>;
	stepA->fnPtr = &BeatCollector::collectData;
	stepA->count = dataPoints;
	addStep(stepA);
	
	Step<BeatCollector>* stepB = new Step<BeatCollector>;
	stepB->fnPtr = &BeatCollector::printData;
	stepB->count = 1;
	addStep(stepB);
}

void BeatCollector::stopLight()
{
	fLEDs.entry(0)->me->color.setColor(*LITColor.colorList[lightCounter]);
	delay(1000);
	lightCounter++;
	
	if (lightCounter == 3)
	{
		fLEDs.entry(0)->me->brightness = 0;
	}
	
}

void BeatCollector::collectData()
{
	for (int n=0;n<7;n++)
	{
		int tmp = audio.eq.spectrum[n]/8;
		specData[n][sampleCount] = (byte) tmp;
	}
	
	sampleCount++;
}

void BeatCollector::printData()
{
	for (int m=0;m<dataPoints;m++)
	{
		for (int n=0;n<7;n++)
		{
			Serial.print(specData[n][m]);
			Serial.print(",");
		}
		Serial.println();
	}
	
	Serial.println();
	Serial.println();
	Serial.println();
	
	delay(5000);
	
	sampleCount = 0;
	lightCounter = 0;
	fLEDs.entry(0)->me->brightness = maxBrightness;
}



