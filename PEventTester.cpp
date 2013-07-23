//	########################################################################

//  PEventTester.cpp

//	7/23/13

//	########################################################################

#include "PEventTester.h"



PEventTester::PEventTester()
{
	createThingsArray();
	things[0] = new SingleRunDot();
}

void PEventTester::update()
{
	if (things[0]->io)
	{
		things[0]->update();
		updateLEDs();
	}
	else
	{
		delete things[0];
	}
	
}

