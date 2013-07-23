//	########################################################################

//  RainbowThing.h

//	7/23/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__RainbowThing__
#define __LIT_Headband_Simulator__RainbowThing__

#include "Thing.h"

class RainbowThing : public Thing
{
public:
	RainbowThing();
	RainbowThing(int start);
	
	void update();
};


#endif


