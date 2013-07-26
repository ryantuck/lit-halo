//	########################################################################

//  Foo.h

//	7/26/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__Foo__
#define __LIT_Headband_Simulator__Foo__

#include "LIT.h"

class Foo
{
public:
	Foo();
	
	Foo** foos;
	
	int buttplug;
	
	int arrayLength;
	int numberOfFoos;
	
	void createArray();
	void createArray(int num);
	
	void clearArray();
	void destroyArray();
	void resizeArray();
	
	int numItems();
	int lengthOfArray();
	
	void addItem();
	void removeItem(int index);
};



#endif


