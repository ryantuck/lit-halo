//	########################################################################

//  MovingSwitcher.cpp

//	11/24/13

//	########################################################################

#include "MovingSwitcher.h"

MovingSwitcher::MovingSwitcher()
{
	MovingFoo* mover = new MovingFoo;
	addFoo(mover);
	
	mover->addLEDs(LITColor.magenta, maxBrightness, 0, 0);
	
	Step<MovingFoo>* moveStep = new Step<MovingFoo>;
	moveStep->period = 2;
	moveStep->fnPtr = &MovingFoo::move;
	mover->addStep(moveStep);
	
	Step<MovingSwitcher>* listen = new Step<MovingSwitcher>;
	listen->fnPtr = &MovingSwitcher::listenUp;
	addStep(listen);
}

void MovingSwitcher::listenUp()
{
	if (audio.beatJustDetected(3))
	{
		MovingFoo* mfPtr = (MovingFoo*)foos.entry(0)->me;
		mfPtr->switchDirection();
	}
}