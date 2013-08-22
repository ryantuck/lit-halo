//	########################################################################

//  EphemeralSnakesFoo.cpp

//	8/21/13

//	########################################################################

#include "EphemeralSnakesFoo.h"

EphemeralSnakesFoo::EphemeralSnakesFoo()
{
	maxFoos = 8;
	
	Step<EphemeralSnakesFoo>* aStep = new Step<EphemeralSnakesFoo>;
	aStep->fnPtr = &EphemeralSnakesFoo::doStuff;
	addStep(aStep);
}

void EphemeralSnakesFoo::doStuff()
{
	if (foos.length() < maxFoos)
	{
		createNewSnake();
	}
}

void EphemeralSnakesFoo::createNewSnake()
{
	EphemeralSnake* aSnake = new EphemeralSnake;
	addFoo(aSnake);
}



EphemeralSnake::EphemeralSnake()
{
	relevantAddress = rand()%32;
	length = rand()%5 + 5;
	direction = rand()%2;
	repeats = false;
	color = LITColor.spectrum[rand()%12];
	layer = rand()%5+1;
	
	//addLEDs(*color, maxBrightness, relevantAddress,relevantAddress);
	
	Step<EphemeralSnake>* growStep = new Step<EphemeralSnake>;
	growStep->fnPtr = &EphemeralSnake::grow;
	growStep->count = length;
	addStep(growStep);
	
	Step<EphemeralSnake>* shrinkStep = new Step<EphemeralSnake>;
	shrinkStep->fnPtr = &EphemeralSnake::shrink;
	shrinkStep->count = length;
	addStep(shrinkStep);
}

EphemeralSnake::EphemeralSnake(int aAddress,
							   int aLength,
							   bool aDirection,
							   Color* aColor)
{
	relevantAddress = aAddress;
	length = aLength;
	direction = aDirection;
	color = aColor;
	repeats = false;
	
	Step<EphemeralSnake>* growStep = new Step<EphemeralSnake>;
	growStep->fnPtr = &EphemeralSnake::grow;
	growStep->count = length;
	addStep(growStep);
	
	Step<EphemeralSnake>* shrinkStep = new Step<EphemeralSnake>;
	shrinkStep->fnPtr = &EphemeralSnake::shrink;
	shrinkStep->count = length;
	addStep(shrinkStep);
}

void EphemeralSnake::grow()
{
	relevantAddress = updateValue(relevantAddress, direction, 0, 31, cycles);
	
	addLEDs(*color, maxBrightness, relevantAddress, relevantAddress);
}

void EphemeralSnake::shrink()
{
	fLEDs.removeEntry(0);
}

EvenEphemSnakes::EvenEphemSnakes()
{
	Step<EvenEphemSnakes>* aStep = new Step<EvenEphemSnakes>;
	aStep->fnPtr = &EvenEphemSnakes::checkForNoSnakes;
	addStep(aStep);
}

void EvenEphemSnakes::checkForNoSnakes()
{
	if (!hasFoos())
	{
		for (int n=0;n<2;n++)
		{
			EphemeralSnake* aSnake = new EphemeralSnake(n*16,16,1,LITColor.spectrum[n]);
			addFoo(aSnake);
		}
	}
}









































