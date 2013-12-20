//	########################################################################

//  BrightnessFrequency.h

//	11/24/13

//	########################################################################

#ifndef __litHeadbandSimulator__BrightnessFrequency__
#define __litHeadbandSimulator__BrightnessFrequency__

#include "Foo.h"

class BrightnessFrequency : public Foo
{
public:
	BrightnessFrequency();
	BrightnessFrequency(int aBand,Color aColor,int aStart);
	void listenUp();
	
	int band;
	int start;
};

class BF4 : public Foo
{
public:
	BF4();
};


#endif


