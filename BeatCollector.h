//	########################################################################

//  BeatCollector.h

//	1/24/14

//	########################################################################

#ifndef __litHeadbandSimulator__BeatCollector__
#define __litHeadbandSimulator__BeatCollector__

#include "Foo.h"

class BeatCollector : public Foo
{
public:
	BeatCollector();
	
	
	void stopLight();
	void collectData();
	void printData();
	
	int sampleCount;
	int lightCounter;
	int dataPoints;
	
	byte specData[7][100];
	
};

#endif


