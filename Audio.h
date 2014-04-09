//	####################################################################

//	Audio.h

//	*	Handles MSGEQ7 and potentiometer interactions.
//	*	Handles all audio processing.


//	####################################################################

#ifndef __Audio__
#define __Audio__

#include "MSGEQ7.h"
#include "MCP4131.h"
#include "Arduino.h"
#include "Beats.h"

//#include "LITFunctions.h"

class Audio
{
public:
	
	MSGEQ7		eq;
	MCP4131		pot;
	Beats		beats;
    Beats       beats2;
	
	int lastSpectrum[7];
	
	int averagedSpectrum[7];
	int avgCounter;
    
    bool bassBeatDetected;
    
	
	//	Constructor
	Audio();
	
	//	Grabs eq, weighs it, and checks for beats.
	void update();
	
	//	Updates beatCounters.
	void checkBeats();
	
	//	Sample.
	void getEQ();
	
	void recordSpectrum();
	
	//	Convert spectrum into more usable data.
	void convertEQ();
	
	//	Returns true if beat detected on band.
	bool checkForBeat(byte band);
	
	//	Adjusts pot to try to average spectrum.
	void adjustPot();
	
	//	For testing.
	void gatherSpectrumAverages();

	void updateRunningAverages(int numDataPoints);
	void checkRunningAverages();

	void printSpectrum();
	void printAvgSpectrum();
	
};

#endif
