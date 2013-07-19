//	########################################################################

//  PatternB.cpp

//	5/3/13

//	########################################################################

#include "PatternB.h"


PatternB::PatternB()
{
	createThingsArray();
	things[0] = new Thing2(LITColor.green,0,4,0);
}

void PatternB::update()
{
	things[0]->update();
	updateLEDs();
}