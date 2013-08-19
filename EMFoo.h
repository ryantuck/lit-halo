//	########################################################################

//  EMFoo.h

//	8/16/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__EMFoo__
#define __LIT_Headband_Simulator__EMFoo__

#include "Foo.h"

class EMFoo : public Foo
{
public:
	EMFoo();
	
	int k;
	
	int calculateForceOnFoo();
};



#endif


