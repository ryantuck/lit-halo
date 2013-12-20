//	########################################################################

//  stepFoo1.cpp

//	8/14/13

//	########################################################################

#include "stepFoo1.h"

StepFoo1::StepFoo1()
{
	addLEDs(LITColor.orange, maxBrightness, 5, 5);
	
	Step<StepFoo1>* stepA = new Step<StepFoo1>;
	Step<StepFoo1>* stepB = new Step<StepFoo1>;
	
	stepA->fnPtr = &StepFoo1::moveRight;
	stepB->fnPtr = &StepFoo1::moveLeft;
	
	stepA->count = 10;
	stepB->count = 4;
	
	stepA->period = 4;
	stepB->period = 2;
	
	addStep(stepA);
	addStep(stepB);
}

