//	########################################################################

//  stepFoo1.cpp

//	8/14/13

//	########################################################################

#include "stepFoo1.h"

StepFoo1::StepFoo1()
{
	addLEDs(LITColor.orange, maxBrightness, 5, 5);
	
	Step<ArrayOfFunctionsFoo>* step1 = createStep();
	Step<ArrayOfFunctionsFoo>* step2 = createStep();
		
	step1->fnPtr = &ArrayOfFunctionsFoo::moveRight;
	step2->fnPtr = &ArrayOfFunctionsFoo::moveLeft;
	
	step1->count = 10;
	step2->count = 10;
}