//	########################################################################

//  EverythingTester.h

//	1/24/14

//	########################################################################

#ifndef __litHeadbandSimulator__EverythingTester__
#define __litHeadbandSimulator__EverythingTester__

#include "Foo.h"
#include "Stats.h"
#include "LITFunctions.h"

class EverythingTester : public Foo
{
public:
	EverythingTester();
	void collectData();
	void displayData();
	void updateParameters();
	void changeFoos();
	
	int numSamples;
	int sampleCount;
	
	int potIndex;
	int brIndex;
	int numIndex;
	
	int spectrumData[7];
	
	Stats* stats[7];
};




#endif


