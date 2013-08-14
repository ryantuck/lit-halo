//	########################################################################

//  MovingFoo.cpp

//	8/14/13

//	########################################################################

#include "MovingFoo.h"

MovingFoo::MovingFoo()
{
	
}

void MovingFoo::move(bool direction)
{
	if (hasLEDs())
	{
		for (int n=0;n<countLEDs();n++)
		{
			byte addr = fLEDs.entry(n)->me->address;
			addr = updateValue(addr, direction, 0, 31, 1);
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