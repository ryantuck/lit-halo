//	####################################################################
//
//	MSGEQ7.h
//
//	####################################################################

#ifndef ____MSGEQ7__
#define ____MSGEQ7__

#include "Arduino.h"

class MSGEQ7
{
public:
	
	int spectrum[7];
	
	//	Constructor
	MSGEQ7();
	
	//	takes in 7-band spectrum
	void sample();
	
	//	Returns values of interest from spectrum
	int		spectrumSum();
	int		spectrumAvg();
	int		spectrumMax();
	int		spectrumMin();
	
	//	Subtracts input from each band in spectrum
	void	subtractBaseline(int baseline);
	
	//	Returns band with max/min values
	byte	maxBand();
	byte	minBand();
	
	//	Find centroid.
	float centroid();
	
private:
	
	int analogPin;
	int strobePin;
	int resetPin;
};

#endif
