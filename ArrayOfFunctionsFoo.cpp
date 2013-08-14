//	########################################################################

//  ArrayOfFunctionsFoo.cpp

//	8/9/13

//	########################################################################

#include "ArrayOfFunctionsFoo.h"

ArrayOfFunctionsFoo::ArrayOfFunctionsFoo()
{
	//	create a list object shell for a step
	ListObject<Step<Foo>>* stepLO1 = new ListObject<Step<Foo>>;
	
	//	create a step
	Step<Foo>* aStep = new Step<Foo>;

	//	generally, the following lines can happen in any order.
	//	that's why pointers are great. 
	
	//	assign a function and count to the step
	aStep->fnPtr = &Foo::switchDirection;
	aStep->count = 10;
	
	//	add the step list object to the steps list
	steps.addToEnd(stepLO1);
	
	//	assign the step to the list object
	stepLO1->me = aStep;
	
	ListObject<Step<Foo>>*		stepLO2	= new ListObject<Step<Foo>>;
	Step<ArrayOfFunctionsFoo>*	bStep	= new Step<ArrayOfFunctionsFoo>;
	stepLO2->me		= (Step<Foo>*)bStep;
	bStep->fnPtr	= &ArrayOfFunctionsFoo::printALine;
	bStep->count	= 5;
	steps.addToEnd(stepLO2);
	
	currentStep = 0;
	isRecurring = 1;
}

int ArrayOfFunctionsFoo::countSteps()
{
	return steps.length();
}

void ArrayOfFunctionsFoo::update()
{
	if (isRunning)
	{
		doAFunction(steps.entry(currentStep));
		steps.entry(currentStep)->me->iterate();
		checkSteps();
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
			else				isRunning	= false;
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












