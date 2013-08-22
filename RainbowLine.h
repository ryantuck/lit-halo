//	########################################################################

//  RainbowLine.h

//	8/22/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__RainbowLine__
#define __LIT_Headband_Simulator__RainbowLine__

#include "Foo.h"
#include "MovingFoo.h"

class RainbowLine : public MovingFoo
{
public:
	RainbowLine(int length,int start);
};

class RainbowPulser: public Foo
{
public:
	RainbowPulser();
	
	int counter;
	bool isIncreasing;
	
	void drawNewLine();
};


#endif


