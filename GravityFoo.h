//	########################################################################

//  GravityFoo.h

//	8/16/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__GravityFoo__
#define __LIT_Headband_Simulator__GravityFoo__

#include "Foo.h"

class GravityFoo : public Foo
{
public:
	GravityFoo();
	
	int G;	// gravitational constant
	
	int calculateForceOnFoo(Foo* aFoo);
	
};



#endif


