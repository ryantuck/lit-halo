//	########################################################################

//  MultipleBouncingFoos.h

//	8/5/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__MultipleBouncingFoos__
#define __LIT_Headband_Simulator__MultipleBouncingFoos__

#include "Foo.h"

class MultipleBouncingFoo : public Foo
{
public:
	MultipleBouncingFoo();
	
	void update();
	
private:
	bool isNextTo();
};



#endif


