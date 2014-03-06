//	########################################################################

//  RainbowFountain.h

//	1/31/14

//	########################################################################

#ifndef __litHeadbandSimulator__RainbowFountain__
#define __litHeadbandSimulator__RainbowFountain__

#include "Foo.h"
#include "MovingFoo.h"

class RainbowFountain : public Foo
{
public:
	RainbowFountain(bool aDirection);
	void iterate();
	
	bool direction;
	int cIndex;
};


#endif


