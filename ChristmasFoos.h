//	########################################################################

//  ChristmasFoos.h

//	1/24/14

//	########################################################################

#ifndef __litHeadbandSimulator__ChristmasFoos__
#define __litHeadbandSimulator__ChristmasFoos__

#include "Foo.h"
#include "MovingFoo.h"
#include "EphemeralSnakesFoo.h"

class RedGreenMover : public Foo
{
public:
	RedGreenMover();
};

class RedGreenPulser : public Foo
{
public:
	RedGreenPulser();
	
	void redUpGreenDown();
	void redDownGreenUp();
	
	int pulseCounter;
};

class RedGreenAlternater : public Foo
{
public:
	RedGreenAlternater();
	
	void aUp();
	void bUp();
	
	void add1Up();
	void add2Up();
	
	int add1;
	int add2;
};

class ChristmasSnakes : public Foo
{
public:
	ChristmasSnakes();
	
	void checkForNoSnakes();
	
	int numSnakes;
	
	int count;
	
	int baseCycler;
};

class ChristmasSparkler : public Foo
{
public:
	ChristmasSparkler();
	
	void newSparkle();
	void stall();
	bool checkAddresses(int x);
	
	Color rgw[3];
	
	int totalSparkles;
	
	int colorCount;
};

class InAndOutFader : public Foo
{
public:
	InAndOutFader(Color aColor, int addr);
	
	void getBrighter();
	
	void dimDown();
	
	void fade();
	
	int totalIterations;
};



#endif


