//	####################################################################
//
//	Pattern.cpp
//
//	####################################################################

#include "Pattern.h"

Pattern::Pattern()
{
//	totalSequences = 1;
//	sequences = new Sequence*[totalSequences];
}

Pattern::~Pattern()
{
	Serial.println("Pattern destructor");
	for (int n=0;n<numSequences();n++)
		delete sequences[n];
	
	delete [] sequences;
	sequences = NULL;
}

void Pattern::linkUp()
{
	Serial.println("pattern linkup");
	
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
	for (int i=0;i<numSequences();i++)
		sequences[i]->update();
}

int Pattern::numSequences()
{
	int tmpSum = 0;
	
	for (int n=0;n<totalSequences;n++)
		if(sequences[n] != NULL)
			tmpSum++;

	return tmpSum;
}

void Pattern::rearrangeSequences()
{
	int index = 0;
	
	while (index < totalSequences)
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