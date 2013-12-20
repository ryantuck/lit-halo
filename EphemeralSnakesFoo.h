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
	EphemeralSnake(int address, int length, bool direction, Color* aColor);
	
	int relevantAddress;
	int length;
	Color* color;
	
	void grow();
	void shrink();
};

class EvenEphemSnakes : public Foo
{
public:
	EvenEphemSnakes();
	
	void checkForNoSnakes();
	
	int numSnakes;
	
	int count;
	
	int baseCycler;
};


#endif


