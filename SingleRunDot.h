//	########################################################################

//  SingleRunDot.h

//	7/23/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__SingleRunDot__
#define __LIT_Headband_Simulator__SingleRunDot__

#include "Thing.h"

class SingleRunDot : public Thing
{
public:
	SingleRunDot();
	SingleRunDot(Color aColor);
	
	int currentAddress;
	
	void update();
};



#endif


