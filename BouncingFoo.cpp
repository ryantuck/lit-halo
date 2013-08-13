//	########################################################################

//  BouncingFoo.cpp

//	8/5/13

//	########################################################################

#include "BouncingFoo.h"

BouncingFoo::BouncingFoo()
{
	currentDirection = 1;
	setBlock(LITColor.red, maxBrightness, 0, 0);
}

BouncingFoo::BouncingFoo(Color aColor, int start,int aPeriod)
{
	currentDirection = 1;
	setBlock(aColor, maxBrightness, start, start);
	period = aPeriod;
}

void BouncingFoo::update()
{
	if (currentLocation() == 31)
		currentDirection = 0;
	else if (currentLocation() == 0)
		currentDirection = 1;
	
	move(currentDirection);
}

byte BouncingFoo::currentLocation()
{
	return fLEDs[0]->address;
}

void BouncingFoo::switchDirection()
{
	if (currentDirection)	currentDirection = 0;
	else					currentDirection = 1;
}

void BouncingFoo::checkForSwitch(bool needsToSwitch)
{
	if (needsToSwitch) switchDirection();
}



