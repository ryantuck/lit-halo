//	########################################################################

//  BouncingFoo.h

//	8/5/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__BouncingFoo__
#define __LIT_Headband_Simulator__BouncingFoo__

#include "Foo.h"

class BouncingFoo : public Foo
{
public:
	BouncingFoo();
	
	BouncingFoo(Color aColor, int start, int aPeriod);
	
	bool currentDirection;
	
	void update();
	
	byte currentLocation();
	
	void switchDirection();
	
	void checkForSwitch(bool needsToSwitch);
	
};



#endif


