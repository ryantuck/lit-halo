//	########################################################################

//  PatternA.cpp

//	5/2/13

//	########################################################################

#include "PatternA.h"


PatternA::PatternA()
{
	createThingsArray();
	things[0] = new Thing2(LITColor.orange,1,5,0);
	things[1] = new Thing2(LITColor.red,9,11,1);
	things[2] = new Thing2(LITColor.green,14,19,0);
	
	things[0]->period		= 10;
	things[1]->period		= 3;
	things[2]->io			= 1;
}

void PatternA::update()
{
	genericUpdate();
}

