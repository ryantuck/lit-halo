//	########################################################################

//  SixDots.h

//	1/30/14

//	########################################################################

#ifndef __litHeadbandSimulator__SixDots__
#define __litHeadbandSimulator__SixDots__

#include "Foo.h"
#include "MovingFoo.h"

class SixDots : public Foo
{
public:
	SixDots();
	void listen();
	
	bool switcher;
};


#endif


