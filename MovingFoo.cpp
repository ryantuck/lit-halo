//	########################################################################

//  MovingFoo.cpp

//	8/14/13

//	########################################################################

#include "MovingFoo.h"

MovingFoo::MovingFoo()
{
	direction = 0;
}

void MovingFoo::move()
{
	move(direction);
}

void MovingFoo::move(bool direction)
{
	if (hasLEDs())
	{
		for (int n=0;n<countLEDs();n++)
		{
			byte addr = fLEDs.entry(n)->me->address;
			addr = updateValue(addr, direction, 0, 31, cycles);
			fLEDs.entry(n)->me->address = addr;
		}
	}
}

void MovingFoo::moveLeft()
{
	move(0);
}

void MovingFoo::moveRight()
{
	move(1);
}

void MovingFoo::switchDirection()
{
	if (direction)	direction = 0;
	else			direction = 1;
}

// ===========================================================

MovingDot::MovingDot(Color aColor, bool aDirection, int aAddress)
{
	aAddress = checkAddress(aAddress);
	
	addLEDs(aColor, maxBrightness, aAddress, aAddress);
	
	direction = aDirection;
	
//	Step<MovingFoo>* m = new Step<MovingFoo>;
//	m->fnPtr = &MovingFoo::move;
//	addStep(m);
	
	addStepWithFunction(&MovingFoo::move, 1);
}









