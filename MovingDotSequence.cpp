//	####################################################################

//	MovingDotSequence.cpp

//	####################################################################

#include "MovingDotSequence.h"

MovingDotSequence::MovingDotSequence()
{
	createElementsArray(3);
	
	for (int n=0;n<maxElements;n++)
	{
		elements[n] = new DotElement;
		elements[n]->rate = 5*n;
	}
}

void MovingDotSequence::update()
{
	for (int n=0;n<numElements();n++)
	{
		elements[n]->segments[0]->color.setColor(colors[n]);
		elements[n]->rateCounter++;
		
		if (elements[n]->canUpdate())
		{
			elements[n]->move(n % 2);
			elements[n]->rateCounter = 0;
		}
		
		elements[n]->update();
	}
}

