//	########################################################################

//  RainbowPulser.h

//	12/20/13

//	########################################################################

#ifndef __RainbowPulser__
#define __RainbowPulser__

#include "Foo.h"
#include "RainbowLine.h"

class RainbowPulser: public Foo
{
public:
	RainbowPulser();
	
	int counter;
	bool isIncreasing;
	
	void drawNewLine();
};

class DoubleRainbowPulser : public Foo
{
	// this thing looks ok. improve or remove.
	
public:
	DoubleRainbowPulser();
	
	int counter;
	
	void drawNewLines();
};

#endif
