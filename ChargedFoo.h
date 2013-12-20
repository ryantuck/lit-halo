//	########################################################################

//  ChargedFoo.h

//	8/16/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__ChargedFoo__
#define __LIT_Headband_Simulator__ChargedFoo__

#include "Foo.h"
#include "MovingFoo.h"

class ChargedFoo : public MovingFoo
{
public:
	ChargedFoo();
	
	int		charge;
	bool	isPositive;
	
	void	reactToForce(Force aForce);
};



#endif


