//	####################################################################

//	MovingDotSequence.cpp

//	####################################################################

#include "SeqMovingDot.h"

SeqMovingDot::SeqMovingDot()
{
	createElementsArray(1);
	
	for (int n=0;n<maxElements;n++)
	{
		elements[n] = new DotElement;
	}
}

void SeqMovingDot::update()
{
	elements[0]->update();
}

