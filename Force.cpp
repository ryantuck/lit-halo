//	########################################################################

//  Force.cpp

//	8/20/13

//	########################################################################

#include "Force.h"

Force::Force()
{
	magnitude = 0;
	direction = 0;
}

void Force::addForce(Force otherForce)
{
	if (direction == otherForce.direction)
	{
		magnitude += otherForce.magnitude;
	}
	else
	{
		if (magnitude > otherForce.magnitude)
		{
			magnitude -= otherForce.magnitude;
		}
		else
		{
			magnitude = otherForce.magnitude - magnitude;
			direction = otherForce.direction;
		}
	}
}