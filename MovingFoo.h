//	########################################################################

//  MovingFoo.h

//	8/14/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__MovingFoo__
#define __LIT_Headband_Simulator__MovingFoo__

#include "Foo.h"

class MovingFoo : public Foo
{
public:
	MovingFoo();
	
	void move(bool direction);
	
	void moveLeft();
	void moveRight();
};



#endif


