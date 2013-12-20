//	########################################################################

//  RainbowLine.h

//	8/22/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__RainbowLine__
#define __LIT_Headband_Simulator__RainbowLine__

#include "Foo.h"
#include "MovingFoo.h"

class RainbowLine : public Foo
{
public:
	RainbowLine(int length,int start);
};

class DoubleRainbow : public MovingFoo
{
public:
	DoubleRainbow();
};






#endif


