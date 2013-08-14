//	########################################################################

//  ArrayOfFunctionsFoo.cpp

//	8/9/13

//	########################################################################

#include "ArrayOfFunctionsFoo.h"

ArrayOfFunctionsFoo::ArrayOfFunctionsFoo()
{	
	currentStep = 0;
	isRecurring = true;
	isRunning	= true;
}

int ArrayOfFunctionsFoo::countSteps()
{
	return steps.length();
}

void ArrayOfFunctionsFoo::update()
{
	if (isRunning)
	{
		if (hasSteps())
		{
			doAFunction(steps.entry(currentStep));
			steps.entry(currentStep)->me->iterate();
			checkSteps();
		}
	}
}

void ArrayOfFunctionsFoo::doAFunction(ListObject<Step<Foo> > * obj)
{
	(*this.*obj->me->fnPtr)();
}

void ArrayOfFunctionsFoo::checkSteps()
{
	if (steps.entry(currentStep)->me->isFinished)
	{
		currentStep++;
		
		if (currentStep == countSteps())
		{
			if (isRecurring)	resetSteps();
			else				isRunning = false;
		}
	}
}

void ArrayOfFunctionsFoo::resetSteps()
{
	currentStep = 0;
	
	for (int n=0;n<countSteps();n++)
	{
		steps.entry(n)->me->currentCount	= 0;
		steps.entry(n)->me->isFinished		= false;
	}
}

void ArrayOfFunctionsFoo::printALine()
{
	Serial.println("printing a line");
}

void ArrayOfFunctionsFoo::moveLeft()
{
	move(1);
}

void ArrayOfFunctionsFoo::moveRight()
{
	move(0);
}

bool ArrayOfFunctionsFoo::hasSteps()
{
	if (countSteps())	return 1;
	else				return 0;
}

//Step<ArrayOfFunctionsFoo>* ArrayOfFunctionsFoo::createStep()
//{
//	ListObject<Step<Foo>>* lo1 = new ListObject<Step<Foo>>;
//	Step<ArrayOfFunctionsFoo>* step1 = new Step<ArrayOfFunctionsFoo>;
//	lo1->me = (Step<Foo>*)step1;
//	steps.addToEnd(lo1);
//	return step1;
//}









