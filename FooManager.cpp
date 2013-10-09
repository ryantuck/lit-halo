//	########################################################################

//  FooManager.cpp

//	8/21/13

//	########################################################################

#include "FooManager.h"

FooManager::FooManager()
{
	foo			= NULL;
	foodex		= 0;
	maxFoodex	= 8;
}

void FooManager::update()
{
	updateFoo(foodex);
}

void FooManager::updateFoo(int index)
{
	if (foo)
	{
		delete foo;
		foo = NULL;
	}
	
	createNewFoo(index);
}

void FooManager::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new KernFoo;
			break;
		case 1:
			foo = new StepFoo1;
			break;
		case 2:
			foo = new Foo2;
			break;
		case 3:
			foo = new LinkedFoo;
			break;
		case 4:
			foo = new RainbowFoo;
			break;
		case 5:
			foo = new EventFoo;
			break;
		case 6:
			foo = new OscillatingFoo;
			break;
		case 7:
			foo = new MultipleBouncingFoo;
			break;
		case 8:
			foo = new CirclesFoo;
			break;
	}
}

DevFooManager::DevFooManager()
{
	maxFoodex = 8;
}

void DevFooManager::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new MultipleBouncingFoo;
			break;
		case 1:
			foo = new RainbowFoo;
			break;
		case 2:
			foo = new CirclesFoo;
			break;
		case 3:
			foo = new EphemeralSnakesFoo;
			break;
		case 4:
			foo = new EvenEphemSnakes;
			break;
		case 5:
			foo = new RainbowLine(32,0);
			break;
		case 6:
			foo = new AListener;
			break;
		case 7:
			foo = new BandMeter;
			break;
		case 8:
			foo = new BandMeterFoo;
	}
}




















