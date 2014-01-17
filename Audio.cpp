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
	
	silenceSlopes[0] = -0.035;
	silenceSlopes[1] = -0.113;
	silenceSlopes[2] = -0.196;
	silenceSlopes[3] = -0.320;
	silenceSlopes[4] = -0.463;
	silenceSlopes[5] = -0.790;
	silenceSlopes[6] = -0.665;
	
	silenceIntercepts[0] = 63.4;
	silenceIntercepts[1] = 75.2;
	silenceIntercepts[2] = 100.4;
	silenceIntercepts[3] = 108.8;
	silenceIntercepts[4] = 135.1;
	silenceIntercepts[5] = 178.2;
	silenceIntercepts[6] = 205.7;
	
	avgCounter = 0;
    
    for(int n=0;n<7;n++)
    {
        beatCounters[n] = 0;
        beatDetected[n] = 0;
    }
    
    //initialize pot value upon startup -DK
    pot.update(2);
}

void Audio::update()
{
	getEQ();
    for(int n=0;n<7;n++)
    {
        stats[n].update(eq.spectrum[n]);
    }
    
	checkBeats();
}

void Audio::getEQ()
{
	eq.sample();
}


void Audio::checkBeats()
{
    for(int n=0;n<6;n++)
    {
        if(beatCounters[n] < 10)  beatCounters[n]++;
        beatDetected[n] = 0;
       
        //if sample is larger than 2 standard devs
        if(abs(eq.spectrum[n] - stats[n].getMean())
           > 2*stats[n].getStdev() && beatCounters[n] >= 10)
        {
            beatCounters[n] = 0;
            beatDetected[n] = 1;
            
//            Serial.println("beat detected on band ");
//            Serial.println(n);
        }
    }
}

bool Audio::checkForBeat(byte band)
{
	//	Returns true if beat is detected.
	
	if (beatCounters[band] == 0)
		if (eq.spectrum[band] > 300)
			return 1;
	
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

bool Audio::beatJustDetected(byte band)
{
	if (beatCounters[band] == 1)	return true;
	else							return false;
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

int Audio::baseline(int band, int potValue)
{
	int bl = silenceSlopes[band] * potValue + silenceIntercepts[band];
	return bl;
}

void Audio::subtractBaselines()
{
	int potVal = pot.currentValue;
	
	for (int n=0;n<7;n++)
	{
		int bl = baseline(n,potVal);
		eq.spectrum[n] -= bl;
		
		if (eq.spectrum[n] < 0) eq.spectrum[n] = 0;
	}
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
		updateWeightSpectrum();
		
		avgCounter = 0;
		for (int n=0;n<7;n++)	averagedSpectrum[n] = 0;
	}
	else
	{
		avgCounter++;
		updateRunningAverages(avgCounter);
	}
}

void Audio::updateWeightSpectrum()
{
	
}









