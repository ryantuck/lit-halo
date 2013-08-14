//	########################################################################

//  stepFoo1.cpp

//	8/14/13

//	########################################################################

#include "stepFoo1.h"

StepFoo1::StepFoo1()
{
	addLEDs(LITColor.orange, maxBrightness, 5, 5);
	
//	Step<StepFoo1>* step1 = createStep<StepFoo1>();
//	Step<StepFoo1>* step2 = createStep<StepFoo1>();
//		
//	step1->fnPtr = &StepFoo1::moveRight;
//	step2->fnPtr = &StepFoo1::moveLeft;

	Step<StepFoo1>* stepA = new Step<StepFoo1>;
	Step<StepFoo1>* stepB = new Step<StepFoo1>;
	
	stepA->fnPtr = &StepFoo1::moveRight;
	stepB->fnPtr = &StepFoo1::moveLeft;
	
	stepA->count = 10;
	stepB->count = 4;
	
	stepA->period = 4;
	
	addStep(stepA);
	addStep(stepB);
	
//	step1->count = 10;
//	step2->count = 10;
}

void StepFoo1::moveLeft()
{
	move(1);
}

void StepFoo1::moveRight()
{
	move(0);
}