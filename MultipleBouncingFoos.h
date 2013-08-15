//	########################################################################

//  MultipleBouncingFoos.h

//	8/5/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__MultipleBouncingFoos__
#define __LIT_Headband_Simulator__MultipleBouncingFoos__

#include "MovingFoo.h"

class MultipleBouncingFoo : public Foo
{
public:
	MultipleBouncingFoo();
	
	void checkForBounces();
	
private:
	bool isNextTo();
};



#endif


