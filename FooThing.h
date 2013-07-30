//	########################################################################

//  FooThing.h

//	7/29/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__FooThing__
#define __LIT_Headband_Simulator__FooThing__

#include "Thing.h"
#include "Foo.h"

class FooThing : public Thing
{
public:
	FooThing();
	
	Foo aFoo;
	
	void update();
};


#endif


