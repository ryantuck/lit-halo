//	########################################################################

//  Thing2.h

//	5/2/13

//	########################################################################

#ifndef __Headband__Thing2__
#define __Headband__Thing2__

#include "Thing.h"

class Thing2 : public Thing
{
public:
	Thing2();
	Thing2(Color aColor, int start, int end, bool aDirection);
	
	bool dir;
	
	void update();
};



#endif


