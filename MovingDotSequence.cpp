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
    
}

void MovingDotSequence::update()
{
	Serial.print("numElements: "); Serial.println(numElements());
	
	Serial.println(numLEDs);
	
	for (int n=0;n<numElements();n++)
	{
		elements[n]->segments[0]->color.setColor(colors[n]);
		
		if (elements[n]->canUpdate())
		{
			elements[n]->move(n % 2);
		}
		
		Serial.println(elements[n]->numLEDs);
		
		elements[n]->update();
	}

}

