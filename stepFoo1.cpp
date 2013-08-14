//	########################################################################

//  stepFoo1.cpp

//	8/14/13

//	########################################################################

#include "stepFoo1.h"

StepFoo1::StepFoo1()
{
	addLEDs(LITColor.orange, maxBrightness, 5, 5);
	
	ListObject<Step<Foo>>* lo1 = new ListObject<Step<Foo>>;
	Step<ArrayOfFunctionsFoo>* step1 = new Step<ArrayOfFunctionsFoo>;
	lo1->me = (Step<Foo>*)step1;
	steps.addToEnd(lo1);
	
	ListObject<Step<Foo>>* lo2 = new ListObject<Step<Foo>>;
	Step<ArrayOfFunctionsFoo>* step2 = new Step<ArrayOfFunctionsFoo>;
	lo2->me = (Step<Foo>*)step2;
	steps.addToEnd(lo2);
	
	step1->fnPtr = &ArrayOfFunctionsFoo::moveRight;
	step2->fnPtr = &ArrayOfFunctionsFoo::moveLeft;
	
	step1->count = 10;
	step2->count = 10;
	
//	currentStep = 0;
//	isRecurring	= 1;
}