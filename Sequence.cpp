//	####################################################################
//
//	Sequence.cpp
//
//	####################################################################

#include "Sequence.h"

Sequence::Sequence()
{
	maxElements	= 1;
	elements = new Element*[maxElements];
	
	io = true;
}

Sequence::~Sequence()
{
	for (int n=0;n<numElements();n++)
		delete elements[n];
	
	delete [] elements;
	elements = NULL;
}

void Sequence::linkUp()
{
	Serial.println("Sequence linkUp");
	
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
			if (elements[index+1] != NULL)
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





















