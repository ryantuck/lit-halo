//	########################################################################

//  EverythingTester.cpp

//	1/24/14

//	########################################################################

#include "EverythingTester.h"

EverythingTester::EverythingTester()
{
	numSamples	= 100;
	sampleCount = 0;
	
	potIndex	= 0;
	brIndex		= 0;
	numIndex	= 0;
	
	for (int n=0;n<7;n++)
	{
		spectrumData[n] = 0;
	}
	
	for (int n=0;n<7;n++)
	{
		stats[n] = new Stats(110);
	}
	
	Step<EverythingTester>* collect = new Step<EverythingTester>;
	collect->fnPtr = &EverythingTester::collectData;
	collect->count = numSamples;
	addStep(collect);
	
	Step<EverythingTester>* display = new Step<EverythingTester>;
	display->fnPtr = &EverythingTester::displayData;
	display->count = 1;
	addStep(display);
	
	Step<EverythingTester>* updParams = new Step<EverythingTester>;
	updParams->fnPtr = &EverythingTester::updateParameters;
	updParams->count = 1;
	addStep(updParams);
	
	Step<EverythingTester>* change = new Step<EverythingTester>;
	change->fnPtr = &EverythingTester::changeFoos;
	change->count = 1;
	addStep(change);
	
}

void EverythingTester::collectData()
{
	// sample 100 times
	sampleCount++;
	
	for (int n=0;n<7;n++)
	{
		int x = spectrumData[n];
		x += (audio.eq.spectrum[n] - x)/sampleCount;
		spectrumData[n] = x;
		
		stats[n]->update(audio.eq.spectrum[n]);
	}
}

void EverythingTester::displayData()
{
	// print out data
	Serial.print(8*potIndex+1);		Serial.print(",");
	Serial.print(25*brIndex);	Serial.print(",");
	Serial.print(8*numIndex);	Serial.print(",");
	
	for (int n=0;n<7;n++)
	{
		Serial.print(spectrumData[n]);
		Serial.print(",");
	}
	
	for (int n=0;n<7;n++)
	{
		stats[n]->getStats();
		Serial.print(stats[n]->stdev);
		Serial.print(",");
	}
	Serial.println();
	
	// delay
	delay(500);
}

void EverythingTester::updateParameters()
{
	// change pot, num, brightness if necessary
	
	potIndex = updateValue(potIndex, up, 0, 15, cycles);
	
	if (potIndex == 0)
	{
		numIndex = updateValue(numIndex, up, 0, 4, cycles);
		
		if (numIndex == 0)
		{
			brIndex	 = updateValue(brIndex, up, 0, 4, cycles);
		}
	}
	
	for (int n=0;n<7;n++)
	{
		spectrumData[n] = 0;
		stats[n]->clear();
	}
	sampleCount = 0;
}

void EverythingTester::changeFoos()
{
	audio.pot.update(8*potIndex+1);
	
	fLEDs.removeAllEntries();
	
	// 0 - none
	// 1 - 8 - every 4
	// 2 - 16 - every 2
	// 3 - 24 - 3 on, 1 off
	// 4 - 32 - all on
	
	if (numIndex > 0)
	{
		for (int n=0;n<8;n++)
		{
			addLEDs(LITColor.white, 25*brIndex, 4*n, 4*n + numIndex - 1);
		}
	}
	
}



