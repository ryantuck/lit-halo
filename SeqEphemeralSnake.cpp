//	########################################################################

//  SeqEphemeralSnake.cpp

//	3/17/13

//	########################################################################

#include "SeqEphemeralSnake.h"


SeqEphemeralSnake::SeqEphemeralSnake()
{
	createElementsArray(1);
	
	elements[0] = new Element;
	pleaseDestroy = 0;
	linkUp();
}

SeqEphemeralSnake::SeqEphemeralSnake(Color myColor,
									 int myStart,
									 int myLength,
									 int myRate,
									 int myLayer,
									 bool myDirection)
{
	createElementsArray(1);
	elements[0] = new Element;
	
	elements[0]->segments[0]->color.setColor(myColor);
	elements[0]->segments[0]->start = myStart;
	
	elements[0]->rate	= myRate;
	elements[0]->layer	= myLayer;
	
	maxLength		= myLength;
	direction		= myDirection;
	growing			= 1;
	pleaseDestroy	= 0;
	
	linkUp();
	
}

void SeqEphemeralSnake::update()
{
	if (elements[0]->canUpdate())
	{
		if (direction)
		{
			if (growing)
			{
				elements[0]->segments[0]->length++;
			}
			else
			{
				elements[0]->segments[0]->length--;
				elements[0]->segments[0]->start++;
			}
		}
		else
		{
			if (growing)
			{
				elements[0]->segments[0]->length++;
				elements[0]->segments[0]->start--;
			}
			else
			{
				elements[0]->segments[0]->length--;
			}
		}
	}
	
	if (elements[0]->segments[0]->length == maxLength)
	{
		growing = 0;
	}
	
	if (!growing && elements[0]->segments[0]->length == 0)
	{
		pleaseDestroy = 1;
	}
	
	elements[0]->update();
}
