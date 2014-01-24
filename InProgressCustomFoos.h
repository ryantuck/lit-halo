//	########################################################################

//  InProgressCustomFoos.h

//	8/23/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__InProgressCustomFoos__
#define __LIT_Headband_Simulator__InProgressCustomFoos__

#include "Foo.h"
#include "MovingFoo.h"
#include "EphemeralSnakesFoo.h"
#include "RainbowLine.h"
#include <math.h>
#include "LITFunctions.h"
#include "SystemMonitors.h"
#include "Stats.h"



class ListenerWithBunch : public Foo
{
public:
	ListenerWithBunch();
	void listenUp();
};

class FiniteBunch : public MovingFoo
{
public:
	FiniteBunch();
};

















#endif







































