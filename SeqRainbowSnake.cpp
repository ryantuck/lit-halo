//	########################################################################

//  SeqRainbowSnake.cpp

//	3/18/13

//	########################################################################

#include "SeqRainbowSnake.h"

SeqRainbowSnake::SeqRainbowSnake()
{
	createElementsArray(1);
	
	elements[0] = new RainbowSnakeElement;
}

void SeqRainbowSnake::update()
{
	if (elements[0]->canUpdate())
	{
		elements[0]->move(1);
	}
	
	elements[0]->update();
}
