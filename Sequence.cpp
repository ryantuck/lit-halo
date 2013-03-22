//	####################################################################
//
//	Sequence.cpp
//
//	####################################################################

#include "Sequence.h"

Sequence::Sequence()
{
	clearElements();
	createElementsArray(1);
	
	elements[0] = new Element;
	
	io = true;
}

Sequence::~Sequence()
{
	Serial.println("sequence destructor");
	
	for (int n=0;n<numElements();n++)
	{
		delete elements[n];
		Serial.print(n); Serial.println(" deleted element");
	}
		
	
	for (int n=0;n<maxElements;n++)
		elements[n] = NULL;
		
	
	delete [] elements;
	elements = NULL;
}

void Sequence::linkUp()
{
	for (int i=0;i<numElements();i++)
	{
		elements[i]->leds		= leds;
		elements[i]->audio		= audio;
		elements[i]->numLEDs	= numLEDs;
	}
}

void Sequence::update()
{

}

int Sequence::numElements()
{	
	int count = 0;
	
	for (int n=0;n<maxElements;n++)
		if (elements[n] != NULL)
			count++;

	return count;
}

void Sequence::rearrangeElements()
{
	int index = 0;
	
	while (index < maxElements)
	{
		if (elements[index] != NULL)
			index++;
		else
		{
			if (elements[index+1] != NULL && index != maxElements)
			{
				elements[index]		= elements[index+1];
				elements[index+1]	= NULL;
				index = 0;
			}
			else
				index++;
		}
	}
}

void Sequence::createElementsArray(int number)
{
	maxElements = number;
	elements = new Element*[number];
	
	for (int n=0;n<maxElements;n++)
	{
		elements[n] = NULL;
	}
}

void Sequence::clearElements()
{
	if (elements != NULL)
	{
		if (numElements() != 0)
		{
			for (int n=0;n<numElements();n++)
			{
				delete elements[n];
				Serial.print(n); Serial.println(" deleted element");
			}
			
			
			for (int n=0;n<maxElements;n++)
				elements[n] = NULL;
			
			
			delete [] elements;
			elements = NULL;
		}
	}
}


void Sequence::printVitals()
{
	Serial.print("# Elements: ");
	Serial.println(numElements());
	Serial.print("# LEDs:     ");
	Serial.println(numLEDs);
	Serial.print("IO:         ");
	Serial.println(io);
	Serial.println();
}





















