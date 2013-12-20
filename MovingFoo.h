//	########################################################################

//  MovingFoo.h

//	8/14/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__MovingFoo__
#define __LIT_Headband_Simulator__MovingFoo__

#include "Foo.h"
#include "LITFunctions.h"

class MovingFoo : public Foo
{
public:
	MovingFoo();
	
	bool direction;
	
	void move();
	
	void move(bool direction);
	
	void moveLeft();
	void moveRight();
	
	void switchDirection();
};

class MovingDot : public MovingFoo
{
public:
	MovingDot(Color aColor, bool aDirection, int aAddress);
};



#endif


