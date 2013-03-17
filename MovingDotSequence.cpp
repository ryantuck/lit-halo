//	####################################################################

//	MovingDotSequence.cpp

//	####################################################################

#include "MovingDotSequence.h"

MovingDotSequence::MovingDotSequence()
{
	createElementsArray(1);
	
	for (int n=0;n<maxElements;n++)
	{
		elements[n] = new DotElement;
	}
}

void MovingDotSequence::update()
{
	elements[0]->update();
}

