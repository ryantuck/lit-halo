//	####################################################################

//	MovingDotSequence.cpp

//	####################################################################

#include "SeqMovingDot.h"

SeqMovingDot::SeqMovingDot()
{
	createElementsArray(1);
	
	elements[0] = new DotElement;
}

SeqMovingDot::SeqMovingDot(Color myColor, int myStart)
{
	createElementsArray(1);
	
	elements[0] = new DotElement(myColor,myStart);
}

void SeqMovingDot::update()
{
	elements[0]->update();
}

