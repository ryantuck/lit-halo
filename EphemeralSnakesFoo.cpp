//	########################################################################

//  EphemeralSnakesFoo.cpp

//	8/21/13

//	########################################################################

#include "EphemeralSnakesFoo.h"

EphemeralSnakesFoo::EphemeralSnakesFoo()
{
	maxFoos = 6;
	
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
	
	addStepWithFunction(&EphemeralSnake::grow,1,length);
	addStepWithFunction(&EphemeralSnake::shrink,1,length);
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
	
	addStepWithFunction(&EphemeralSnake::grow,1,length);
	addStepWithFunction(&EphemeralSnake::shrink,1,length);
}

void EphemeralSnake::grow()
{
	if (hasLEDs())
	{
		relevantAddress = updateValue(relevantAddress,
									  direction,
									  0,
									  31,
									  cycles);

	}
		
	addLEDs(*color, maxBrightness, relevantAddress, relevantAddress);
}

void EphemeralSnake::shrink()
{
	fLEDs.removeEntry(0);
}

EvenEphemSnakes::EvenEphemSnakes()
{
	addStepWithFunction<EvenEphemSnakes>(&EvenEphemSnakes::checkForNoSnakes,1);
	
	baseCycler = 0;
}

void EvenEphemSnakes::checkForNoSnakes()
{
	if (!hasFoos())
	{
		for (int n=0;n<2;n++)
		{
			int theIndex = 3*n + baseCycler;
			
			EphemeralSnake* aSnake = new EphemeralSnake(n*16,16,1,LITColor.colorList[theIndex]);
			addFoo(aSnake);
		}
		
		baseCycler = updateValue(baseCycler, up, 0, 2, cycles);
	}
}









































