//	####################################################################

//	LayerTestingSequence.cpp

//	####################################################################

#include "LayerTestingSequence.h"

LayerTestingSequence::LayerTestingSequence()
{
	createElementsArray(3);
	
	elements[0] = new Element;
	elements[1] = new Element;
	elements[2] = new Element;
	
	elements[0]->segments[0] = new Segment(LITColor.red,	5,1);
	elements[1]->segments[0] = new Segment(LITColor.green,	4,1);
	elements[2]->segments[0] = new Segment(LITColor.blue,	3,1);
	
	elements[0]->layer	= 1;
	elements[1]->layer	= 1;
	elements[2]->layer	= 1;
	
	elements[0]->rate	= 100;
	elements[1]->rate	= 50;
	elements[2]->rate	= 25;
}

void LayerTestingSequence::update()
{
	for (int n=0;n<numElements();n++)
	{
		if (elements[n]->canUpdate())
		{
			elements[n]->move(1);
		}
		
		elements[n]->update();
	}
}
