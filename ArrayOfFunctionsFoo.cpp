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
	
	ListObject<Step<Foo>>* stepLO2 = new ListObject<Step<Foo>>;
	Step<ArrayOfFunctionsFoo>* bStep = new Step<ArrayOfFunctionsFoo>;
	bStep->fnPtr = &ArrayOfFunctionsFoo::printALine;
	bStep->count = 5;
	stepLO2->me = (Step<Foo>*)bStep;
	steps.addToEnd(stepLO2);
}

int ArrayOfFunctionsFoo::countSteps()
{
	return steps.length();
}

void ArrayOfFunctionsFoo::update()
{
	for (int n=0;n<countSteps();n++)
	{
		for (int c=0;c<steps.entry(n)->me->count;c++)
		{
			doAFunction(steps.entry(n));
		}
	}
}

void ArrayOfFunctionsFoo::doAFunction(ListObject<Step<Foo> > * obj)
{
	(*this.*obj->me->fnPtr)();
}

void ArrayOfFunctionsFoo::doAFunction(void (*func)())
{
	(*func)();
}

void ArrayOfFunctionsFoo::doAFunction(void (*func)(int), int a)
{
	(*func)(a);
}

void ArrayOfFunctionsFoo::printALine()
{
	Serial.println("printing a line");
}












