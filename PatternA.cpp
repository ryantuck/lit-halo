//	########################################################################

//  PatternA.cpp

//	5/2/13

//	########################################################################

#include "PatternA.h"


PatternA::PatternA()
{
	createThingsArray();
	things[0] = new Thing2(LITColor.blue,1,5,0);
	things[1] = new Thing2(LITColor.red,9,11,1);
}

void PatternA::update()
{
	things[0]->update();
	things[1]->update();
	updateLEDs();
}