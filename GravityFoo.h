//	########################################################################

//  GravityFoo.h

//	8/16/13

//	########################################################################

//started working on physics classes. enables LEDs reactiving to a "graviational force"
//This could be developed into PhysicsFoo heirarchy
#ifndef __LIT_Headband_Simulator__GravityFoo__
#define __LIT_Headband_Simulator__GravityFoo__

#include "Foo.h"

class GravityFoo : public Foo
{
public:
	GravityFoo();
	
	int G;	// gravitational constant
	
	int calculateForceOnFoo(Foo* aFoo);
	
};



#endif


