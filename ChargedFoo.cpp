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
	aStep->period = 100;
	addStep(aStep);
}

void ChargedFoo::reactToForce(Force aForce)
{
	//	force comes in as magnitude in certain direction.
	
	//	if this foo is an electron, reverse the direction of the force.
	
	//	if the acceleration is in the same direction as the motion,
	//		vf = vi + at
	//	else
	//		vf = vi - at
	
	//	if vf < 0
	//		vf = 0-vf
	//		switchDirection
	
	if (!isPositive) aForce.direction = !aForce.direction;
	
	double acceleration = aForce.magnitude / charge;
	bool accelDirection = aForce.direction;
	
	double period = steps.entry(0)->me->period;
	
	double vi = 1/period;
	
	double vf;
	
	if (accelDirection == direction)	vf = vi + acceleration;
	else								vf = vi - acceleration;
	
	if (vf < 0)
	{
		vf = 0-vf;
		switchDirection();
	}
	
	steps.entry(0)->me->period = 1/vf;
}