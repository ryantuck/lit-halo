//	####################################################################
//
//	Audio.cpp
//
//	####################################################################

#include "Audio.h"

//#ifndef FHT_N
//#define FHT_N 256
//#endif


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
    pot.update(9);
    
    TIMSK0 = 0; // turn off timer0 for lower jitter
    ADCSRA = 0xe5; // set the adc to free running mode
    ADMUX = 0x41; // use adc0
    DIDR0 = 0x02; // turn off the digital input for adc0
}

void Audio::update1()
{
	getEQ();
    for(int n=0;n<7;n++)
    {
        stats[n].update(eq.spectrum[n]);
    }
    
	checkBeats();
}

void Audio::update()
{
    cli();  // UDRE interrupt slows this way down on arduino1.0
    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
        while(!(ADCSRA & 0x10)); // wait for adc to be ready
        ADCSRA = 0xf5; // restart adc
        byte m = ADCL; // fetch adc data
        byte j = ADCH;
        int k = (j << 8) | m; // form into an int
        k -= 0x0200; // form into a signed int
        k <<= 6; // form into a 16b signed int
        fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_log(); // take the output of the fht
    sei();
    Serial.write(255); // send a start byte
    Serial.write(fht_log_out, FHT_N/2); // send out the data
}

void Audio::getEQ()
{
	eq.sample();
}


void Audio::checkBeats()
{
    for(int n=0;n<6;n++)
    {
        if(beatCounters[n] < 5)  beatCounters[n]++;
        beatDetected[n] = 0;
       
        //if sample is larger than 2 standard devs
        if(abs(eq.spectrum[n] - stats[n].getMean())
           > 2*stats[n].getStdev() && beatCounters[n] >= 5)
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









