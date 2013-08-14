//	########################################################################

//  EventFoo.h

//	7/30/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__EventFoo__
#define __LIT_Headband_Simulator__EventFoo__

#include "Foo.h"

class EventFoo : public Foo
{
public:
	EventFoo();
	
	int killCounter;
	
	void moveLeft();
};



#endif


