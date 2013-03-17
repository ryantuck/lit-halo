//	########################################################################

//  SeqMovingBlur.cpp

//	3/16/13

//	########################################################################

#include "SeqMovingBlur.h"

SeqMovingBlur::SeqMovingBlur()
{
	createElementsArray(5);
	
	for (int n=0;n<maxElements;n++)
	{
		elements[n] = new DotElement(LITColor.red,n);
		elements[n]->rate = 20;
	}
	
	elements[0]->brightness = 1;
	elements[1]->brightness = 5;
	elements[2]->brightness = 10;
	elements[3]->brightness = 100;
	elements[4]->brightness = 10;
}

SeqMovingBlur::SeqMovingBlur(Color blurColor)
{
	createElementsArray(5);
	
	for (int n=0;n<maxElements;n++)
	{
		elements[n] = new DotElement(blurColor,n);
		elements[n]->rate = 20;
	}
	
	elements[0]->brightness = 1;
	elements[1]->brightness = 10;
	elements[2]->brightness = 25;
	elements[3]->brightness = 100;
	elements[4]->brightness = 25;
}

void SeqMovingBlur::update()
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