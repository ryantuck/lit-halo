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