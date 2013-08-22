//	########################################################################

//  ListenerFoo.h

//	8/22/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__ListenerFoo__
#define __LIT_Headband_Simulator__ListenerFoo__

#include "Foo.h"
#include "MovingFoo.h"

class ListenerFoo : public Foo
{
public:
	ListenerFoo();
	
	void listen();
};

class MovingDot : public MovingFoo
{
public:
	MovingDot();
};


#endif


