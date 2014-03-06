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

DoubleRainbowPulser::DoubleRainbowPulser()
{
	counter	= 0;
	addStepWithFunction(&DoubleRainbowPulser::drawNewLines, 1);
}

void DoubleRainbowPulser::drawNewLines()
{
	foos.removeAllEntries();
	
	counter++;
	
	if (counter == 32)
	{
		counter = 0;
	}
	
	RainbowLine* line1 = new RainbowLine(counter,0);
	addFoo(line1);
	
	RainbowLine* line2 = new RainbowLine(32-counter,counter);
	addFoo(line2);
}
