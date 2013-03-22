//	####################################################################
//
//	Pattern.cpp
//
//	####################################################################

#include "Pattern.h"

Pattern::Pattern()
{
	clearSequences();
	createSequencesArray(1);
	sequences[0] = new Sequence;
}

Pattern::~Pattern()
{
	for (int n=0;n<numSequences();n++)
		delete sequences[n];
	
	for (int n=0;n<maxSequences;n++)
		sequences[n] = NULL;
		
	
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
	int count = 0;
	
	for (int n=0;n<maxSequences;n++)
		if(sequences[n] != NULL)
			count++;

	return count;
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
			if (sequences[index+1] != NULL && index != maxSequences - 1)
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
	
	//	Not sure if this helps
	for (int n=0;n<maxSequences;n++)
	{
		sequences[n] = NULL;
	}
}

void Pattern::clearSequences()
{
	if (sequences != NULL)
	{
		if (numSequences() != 0)
		{
			for (int n=0;n<numSequences();n++)
				delete sequences[n];
			
			for (int n=0;n<maxSequences;n++)
				sequences[n] = NULL;
			
			
			delete [] sequences;
			sequences = NULL;
		}
	}
}




