//	####################################################################
//
//	Audio.cpp
//
//	####################################################################

#include "Audio.h"

Audio::Audio()
{
	for (int n=0;n<7;n++)
	{
		// set these values high so beat isn't automatically detected
		//	on the first iteration
		lastSpectrum[n] = 1000;
	}
	
	avgCounter = 0;
	
	pot.update(1);
    
    beats.derivativeLimit = 80;
    beats2.derivativeLimit = 50;
}

void Audio::update()
{
	getEQ();

	beats.addPoint(eq.spectrum[1]);
    beats2.addPoint(eq.spectrum[2]);
    printSpectrum();
}

void Audio::getEQ()
{
	eq.sample();
}

void Audio::recordSpectrum()
{
	// stores current spectrum to be used in the next iteration
	
	for (int n=0;n<7;n++)
	{
		lastSpectrum[n] = eq.spectrum[n];
	}
}


void Audio::checkBeats()
{
	// beat detection shit
	beats.addPoint(eq.spectrum[1]);
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


void Audio::gatherSpectrumAverages()
{
	for (int n=0;n<7;n++)
	{
		averagedSpectrum[n] = 0;
	}
	
	for (int n=1;n<50;n++)
	{
		eq.sample();
		
		for (int s=0;s<7;s++)
		{
			averagedSpectrum[s] = averagedSpectrum[s] + (eq.spectrum[s] - averagedSpectrum[s]) / n;
		}
	}
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

void Audio::printAvgSpectrum()
{
	for (int n=0;n<7;n++)
	{
		Serial.print(" ");
		if (averagedSpectrum[n] < 10)	Serial.print(" ");
		if (averagedSpectrum[n] < 100)	Serial.print(" ");
		if (averagedSpectrum[n] < 1000)	Serial.print(" ");
		Serial.print(averagedSpectrum[n]);
	}
	Serial.println();
}


void Audio::updateRunningAverages(int numDataPoints)
{
	for (int n=0;n<7;n++)
	{
		averagedSpectrum[n] += (eq.spectrum[n] - averagedSpectrum[n])/numDataPoints;
	}
}

void Audio::checkRunningAverages()
{
	if (avgCounter >= 1000)
	{
		avgCounter = 0;
		for (int n=0;n<7;n++)	averagedSpectrum[n] = 0;
	}
	else
	{
		avgCounter++;
		updateRunningAverages(avgCounter);
	}
}









