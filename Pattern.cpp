//	####################################################################
//
//	Pattern.cpp
//
//	####################################################################

#include "Pattern.h"

Pattern::Pattern()
{
	maxSequences = 1;
	sequences = new Sequence*[maxSequences];
}

Pattern::~Pattern()
{
	for (int n=0;n<numSequences();n++)
		delete sequences[n];
	
	delete [] sequences;
	sequences = NULL;
}

void Pattern::linkUp()
{
	for (int i=0;i<numSequences();i++)
	{
		sequences[i]->numLEDs	= numLEDs;
		sequences[i]->leds		= leds;
		sequences[i]->audio		= audio;
		sequences[i]->colors	= colors;
		sequences[i]->linkUp();
	}
}

void Pattern::update()
{
	Serial.print("num sequences: ");
	Serial.println(numSequences());
	
	for (int i=0;i<numSequences();i++)
		sequences[i]->update();
}

int Pattern::numSequences()
{
	int tmpSum = 0;
	
	for (int n=0;n<maxSequences;n++)
		if(sequences[n] != NULL)
			tmpSum++;

	return tmpSum;
}

void Pattern::rearrangeSequences()
{
	int index = 0;
	
	while (index < maxSequences)
	{
		if (sequences[index] != NULL)
			index++;
		else
		{
			if (sequences[index+1] != NULL)
			{
				sequences[index]	= sequences[index+1];
				sequences[index+1]	= NULL;
				index = 0;
			}
			else
				index++;
		}
	}
}

void Pattern::createSequencesArray(int number)
{
	maxSequences = number;
	sequences = new Sequence*[maxSequences];
}