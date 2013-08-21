//	########################################################################

//  EMFoo.h

//	8/16/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__EMFoo__
#define __LIT_Headband_Simulator__EMFoo__

#include "Foo.h"
#include "ChargedFoo.h"

class EMFoo : public Foo
{
public:
	EMFoo();
	
	int k;
	
	Force calculateForceOnFoo(Foo* aFoo);
	
	void applyForces();
};



#endif


