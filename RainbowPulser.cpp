//
//  RainbowPulser.cpp
//  litHeadbandSimulator
//
//  Created by Alyssa Lerch on 12/20/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "RainbowPulser.h"


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


