//	########################################################################

//  Pattern11.h

//	5/1/13

//	########################################################################

#ifndef __Headband__Pattern11__
#define __Headband__Pattern11__

#include "Pattern.h"
#include "Thing1.h"

class Pattern11 : public Pattern
{
public:
	Pattern11();
	void update();
	
	Thing1 myThing;
};


#endif


