//	########################################################################

//  ArrayOfFunctionsFoo.h

//	8/9/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__ArrayOfFunctionsFoo__
#define __LIT_Headband_Simulator__ArrayOfFunctionsFoo__

#include "Foo.h"

class ArrayOfFunctionsFoo : public Foo
{
public:
	ArrayOfFunctionsFoo();
	
	void update();
	
	void ** steps;
	
	void (*pointerToFunction)(int);
	
};



#endif


