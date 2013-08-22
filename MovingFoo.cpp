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