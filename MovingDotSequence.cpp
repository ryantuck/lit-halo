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
	
	elements[0]->segments[0]->color.setColor(LITColor.red);
	elements[1]->segments[0]->color.setColor(LITColor.green);
	elements[2]->segments[0]->color.setColor(LITColor.blue);
	
    
}

void MovingDotSequence::update()
{	
	for (int n=0;n<numElements();n++)
	{
		if (elements[n]->canUpdate())
		{
			elements[n]->move(n % 2);
		}
		
		elements[n]->update();
	}

}

