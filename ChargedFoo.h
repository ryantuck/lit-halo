//	########################################################################

//  ChargedFoo.h

//	8/16/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__ChargedFoo__
#define __LIT_Headband_Simulator__ChargedFoo__

#include "Foo.h"

class ChargedFoo : public Foo
{
public:
	ChargedFoo();
	
	int		charge;
	bool	isPositive;
};



#endif


