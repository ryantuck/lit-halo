//	########################################################################

//  BatteryFoo.cpp

//	1/7/14

//	########################################################################

#include "BatteryFoo.h"

BatteryFoo::BatteryFoo()
{
	value			= 0;
	valueCounter	= 0;
	repeats			= false;
	
	Step<BatteryFoo>* a = new Step<BatteryFoo>;
	a->fnPtr = &BatteryFoo::readAndCalculate;
	a->count = 1;
	addStep(a);
}

void BatteryFoo::readAndCalculate()
{
	// calculate battery percentage remaining
	value = 20;
	
	// adjust color accordingly
	
	Step<BatteryFoo>* b = new Step<BatteryFoo>;
	b->fnPtr = &BatteryFoo::grow;
	b->count = value;
	addStep(b);
	
	Step<BatteryFoo>* c = new Step<BatteryFoo>;
	c->fnPtr = &BatteryFoo::stall;
	c->count = 60;
	addStep(c);
}

void BatteryFoo::grow()
{
	addLEDs(LITColor.red, maxBrightness, valueCounter, valueCounter);
	
	valueCounter = updateValue(valueCounter, up, 0, value, !cycles);
}

void BatteryFoo::stall()
{
	// do nothing for about 60 iterations
}

