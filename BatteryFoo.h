//	########################################################################

//  BatteryFoo.h

//	1/7/14

//	Initial foo that runs when the user turns the headband on.

//	1. Reads and calculates a percentage of battery capacity left.
//	2. A line of LEDs grows to the corresponding percentage of the headband.
//		these LEDs are colored a continuum of red-green.
//	3. When the user clicks a button, the fooManager's presets will take over.

//	########################################################################

#ifndef __litHeadbandSimulator__BatteryFoo__
#define __litHeadbandSimulator__BatteryFoo__

#include "Foo.h"
#include "EphemeralSnakesFoo.h"
#include "Battery.h"

class BatteryFoo : public Foo
{
public:
	BatteryFoo();
	
	Battery batt;
	
	int value;
	int valueCounter;
	
	void readAndCalculate();
	void grow();
};



#endif


