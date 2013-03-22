//	########################################################################

//  SeqRainbowSnake.cpp

//	3/18/13

//	########################################################################

#include "SeqRainbowSnake.h"

SeqRainbowSnake::SeqRainbowSnake()
{
	clearElements();
	createElementsArray(1);
	
	elements[0] = new RainbowSnakeElement;
	elements[0]->rate = 10;
}

void SeqRainbowSnake::update()
{
	if (elements[0]->canUpdate())
	{
		elements[0]->move(1);
	}
	
	elements[0]->update();
}
