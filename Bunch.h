//	########################################################################

//  Bunch.h

//	11/24/13

//	########################################################################

#ifndef __litHeadbandSimulator__Bunch__
#define __litHeadbandSimulator__Bunch__

#include "Foo.h"
#include "MovingFoo.h"


class Bunch : public MovingFoo
{
public:
	Bunch();
	void listenUp();
	
	int index;
	
};


#endif


