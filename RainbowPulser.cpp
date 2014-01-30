//	########################################################################

//  RainbowPulser.cpp

//	12/20/13

//	########################################################################

#include "RainbowPulser.h"


RainbowPulser::RainbowPulser()
{
	counter			= 0;
	isIncreasing	= true;
	
	addStepWithFunction(&RainbowPulser::drawNewLine,1);
}

void RainbowPulser::drawNewLine()
{
	foos.removeAllEntries();
	
	int start;
	
	if (isIncreasing)
	{
		counter++;
		start = 0;
	}
	else
	{
		counter--;
		start = 32-counter;
	}
	
	if (counter == 32)	isIncreasing = false;
	if (counter ==  1)	isIncreasing = true;
	
	RainbowLine* myLine = new RainbowLine(counter,start);
	addFoo(myLine);
}


