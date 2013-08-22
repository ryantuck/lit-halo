//	########################################################################

//  RainbowLine.cpp

//	8/22/13

//	########################################################################

#include "RainbowLine.h"

RainbowLine::RainbowLine(int length,int start)
{
	for (int n=0;n<length;n++)
	{
		Color aColor = Color(LITColor.black);
		aColor.calculateRGB(length, n);
		
		addLEDs(aColor, maxBrightness, checkAddress(start + n), checkAddress(start + n));
		
		Serial.println(n);
		aColor.printVitals();
	}
	
	Step<MovingFoo>* aStep = new Step<MovingFoo>;
	aStep->fnPtr = &MovingFoo::move;
	addStep(aStep);
}

RainbowPulser::RainbowPulser()
{
	counter			= 0;
	isIncreasing	= true;
	
	Step<RainbowPulser>* aStep = new Step<RainbowPulser>;
	aStep->fnPtr = &RainbowPulser::drawNewLine;
	addStep(aStep);
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

