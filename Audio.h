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
//#include "LITFunctions.h"

class Audio
{
public:
	
	MSGEQ7		eq;
	MCP4131		pot;
	
	int			weightSpectrum[7];
	byte		beatCounters[7];	//	tracks how many iterations
									//	since last beat on each band.
	
	int lastSpectrum[7];
	
	int averagedSpectrum[7];
	int avgCounter;
	
	double silenceSlopes[7];
	double silenceIntercepts[7];
	
	//	Constructor
	Audio();
	
	//	Grabs eq, weighs it, and checks for beats
	void update();
	
	//	Updates beatCounters.
	void checkBeats();
	
	//	Sample.
	void getEQ();
	
	void recordSpectrum();
	
	//	Multiply eq.spectrum by weights.
	void weighEQ();
	
	//	Convert spectrum into more usable data.
	void convertEQ();
	
	//	Returns true if beat detected on band.
	bool checkForBeat(byte band);
	
	//	Adjusts pot to try to average spectrum.
	void adjustPot();
	
	//	For testing.

	void gatherSpectrumAverages();
	
	bool beatJustDetected(byte band);
	
	int baseline(int band, int potValue);
	void subtractBaselines();
	void updateRunningAverages(int numDataPoints);
	void checkRunningAverages();
	void updateWeightSpectrum();
	
	void printBeatCounters();
	void printSpectrum();
	
};

#endif
