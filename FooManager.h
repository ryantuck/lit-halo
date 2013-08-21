//	########################################################################

//  FooManager.h

//	8/21/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__FooManager__
#define __LIT_Headband_Simulator__FooManager__

#include "Foo.h"
#include "CustomFoos.h"

class FooManager
{
public:
	FooManager();
	
	Foo* foo;
	int foodex;
	int maxFoodex;
	
	void update();
	void updateFoo(int index);
};



#endif


