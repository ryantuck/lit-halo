//	########################################################################

//  SeqEphemeralSnake.cpp

//	3/17/13

//	########################################################################

#include "SeqEphemeralSnake.h"


SeqEphemeralSnake::SeqEphemeralSnake()
{
	createElementsArray(1);
	
	elements[0] = new Element;
	io = 1;
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
	
	linkUp();
	
}

void SeqEphemeralSnake::update()
{
	if (elements[0]->canUpdate())
	{
		elements[0]->segments[0]->resize(growing, direction);
	}
	
	if (elements[0]->segments[0]->length == maxLength)
	{
		growing = 0;
	}
	
	if (!growing && elements[0]->segments[0]->length == 1)
	{
		io = 0;
	}
	
	
	Serial.print(growing);							Serial.print(" ");
	Serial.print(direction);						Serial.print(" ");
	Serial.print(maxLength);						Serial.print(" ");
	Serial.print(elements[0]->segments[0]->start);	Serial.print(" ");
	Serial.print(elements[0]->segments[0]->length);	Serial.print(" ");
	Serial.println();
	
	elements[0]->update();
}
