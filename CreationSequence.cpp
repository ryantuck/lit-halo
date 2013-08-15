//	####################################################################

//	CreationSequence.cpp

//	####################################################################

#include "CreationSequence.h"

CreationSequence::CreationSequence()
{
	createElementsArray(4);
}



void CreationSequence::update()
{
	if (audio->checkForBeat(1))
	{
		if (numElements() < 3)
		{
			elements[numElements()] = new DotElement;
			linkUp();
		}
	}
	
	for (int n=0;n<numElements();n++)
	{
		elements[n]->rateCounter++;
		
		if (elements[n]->canUpdate())
		{
			elements[n]->move(1);
		}
		
		elements[n]->update();
		
		if (elements[n]->segments[0]->start == 15)
		{
			delete elements[n];
			
			rearrangeElements();
			
			elements[3]	= NULL;			// necessary?
		}
	}
}
