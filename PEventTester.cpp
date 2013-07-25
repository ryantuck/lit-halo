//	########################################################################

//  PEventTester.cpp

//	7/23/13

//	########################################################################

#include "PEventTester.h"



PEventTester::PEventTester()
{
	createThingsArray();
	things[0] = new SingleRunDot();
	addCounter = 0;
	colorIndex = 0;
}

void PEventTester::update()
{
	if (addCounter == 4)
	{
		addCounter = 0;
		int tmpIndex=0;
		bool added = 0;
		
		while (!added)
		{
			if (things[tmpIndex] == NULL)
			{
				things[tmpIndex] = new SingleRunDot(*LITColor.spectrum[colorIndex]);
				
				colorIndex++;
				if (colorIndex == 12) colorIndex = 0;
				
				added = 1;
			}
			else
				tmpIndex++;
		}
	}
	else
	{
		addCounter++;
	}
	
	for (int n=0;n<8;n++)
	{
		if (things[n] != NULL)
		{
			if (things[n]->readyToDie)
			{
				delete things[n];
				things[n] = NULL;
			}
			else
			{
				things[n]->update();
			}
		}
	}
	
	updateLEDs();
}


