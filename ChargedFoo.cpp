//	########################################################################

//  ChargedFoo.cpp

//	8/16/13

//	########################################################################

#include "ChargedFoo.h"

ChargedFoo::ChargedFoo()
{
	charge		= 1;
	isPositive	= 1;
	
	Step<MovingFoo>* aStep = new Step<MovingFoo>;
	
	aStep->fnPtr = &MovingFoo::move;
	
	addStep(aStep);
}

void ChargedFoo::reactToForce(Force aForce)
{
	// force / charge = acceleration
	//	given an acceleration and current velocity, calculate what velocity should change to?
	
	//	we know that the time has changed by 1. Can we just punch this into vf = vi + at? Why not try it.
	
	double acceleration = aForce.magnitude / charge;
	
	double period = steps.entry(0)->me->period;
	
	double vi = 1/period;
	
	double vf = vi + acceleration;		// vf = vi + at (t = 1)
	
	if (vf < 0)
	{
		vf = 0-vf;
		switchDirection();
	}
	
	steps.entry(0)->me->period = 1/vf;
}