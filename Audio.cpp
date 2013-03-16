//	####################################################################
//
//	Audio.cpp
//
//	####################################################################

#include "Audio.h"

Audio::Audio()
{
	//	Initialize weight spectrum.
	//	Values are percentages.
	
	weightSpectrum[0] = 150;
	weightSpectrum[1] = 120;
	weightSpectrum[2] = 110;
	weightSpectrum[3] = 100;
	weightSpectrum[4] = 110;
	weightSpectrum[5] = 120;
	weightSpectrum[6] = 150;
}

void Audio::update()
{
	getEQ();
	weighEQ();
	checkBeats();
    pot.update(100);
}

void Audio::getEQ()
{
	eq.sample();
}


void Audio::checkBeats()
{
	//	Updates beatCounters[].
	
	for (int n=0;n<7;n++)
	{
		if (checkForBeat(n))			beatCounters[n]++;
		else if (beatCounters[n] != 0)	beatCounters[n]++;
		
		if (beatCounters[n] == 12)		beatCounters[n] = 0;
	}
}

bool Audio::checkForBeat(byte band)
{
	//	** need to ensure this can return 1 and doesn't default to 0.
	
	//	Returns true if beat is detected.
	
	if (beatCounters[band] == 0)
		if (eq.spectrum[band] > 900)	return 1;
	
	return 0;
}

void Audio::weighEQ()
{
	for (int n=0;n<7;n++)
		eq.spectrum[n] *= weightSpectrum[n]/100;
}

void Audio::convertEQ()
{
	int min = eq.spectrumMin();
	eq.subtractBaseline(min);
	
	int		max		= eq.spectrumMax();
	float	ratio	= 1024/max;
	
	for (int n=0;n<7;n++)
		eq.spectrum[n] = eq.spectrum[n]*ratio;
}

void Audio::adjustPot()
{
	int newPotVal = pot.currentValue * 512 / eq.spectrumAvg();
	
	pot.update(newPotVal);
}







void Audio::printBeatCounters()
{
	for (int n=0;n<7;n++)
		Serial.print(beatCounters[n]);	Serial.print(" ");
	
	Serial.println();
}

void Audio::printSpectrum()
{
	for (int n=0;n<7;n++)
	{
		Serial.print(" ");
		if (eq.spectrum[n] < 10)	Serial.print(" ");
		if (eq.spectrum[n] < 100)	Serial.print(" ");
		if (eq.spectrum[n] < 1000)	Serial.print(" ");
		Serial.print(eq.spectrum[n]);
	}
	Serial.println();
}



