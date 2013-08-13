//	########################################################################

//  BounceFoo.h

//	7/31/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__BounceFoo__
#define __LIT_Headband_Simulator__BounceFoo__

#include "Foo.h"

class BounceFoo : public Foo
{
public:
	BounceFoo();
	
	int counter;
	
	void update();
};



#endif


