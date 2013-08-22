//	########################################################################

//  EphemeralSnakesFoo.h

//	8/21/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__EphemeralSnakesFoo__
#define __LIT_Headband_Simulator__EphemeralSnakesFoo__

#include "Foo.h"
#include "MovingFoo.h"

class EphemeralSnakesFoo : public Foo
{
public:
	EphemeralSnakesFoo();
	
	void doStuff();
	
	void createNewSnake();
	
	int maxFoos;
};

class EphemeralSnake : public MovingFoo
{
public:
	EphemeralSnake();
	
	int relevantAddress;
	Color* color;
	
	void grow();
	void shrink();
};



#endif


