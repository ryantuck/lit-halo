//	########################################################################

//  BatteryFoo.h

//	1/7/14

//	########################################################################

#ifndef __litHeadbandSimulator__BatteryFoo__
#define __litHeadbandSimulator__BatteryFoo__

#include "Foo.h"
#include "EphemeralSnakesFoo.h"

class BatteryFoo : public Foo
{
public:
	BatteryFoo();
	
	int value;
	
	int valueCounter;
	
	
	void readAndCalculate();
	void grow();
	void stall();
};



#endif


