//	########################################################################

//  Pattern5.cpp

//	3/17/13

//	########################################################################

#include "Pattern5.h"

Pattern5::Pattern5()
{
	createSequencesArray(8);
	
	//	don't need to create any sequences here.
	//	they will be created randomly in the update() function.
}

void Pattern5::update()
{
	//	if random condition is met && numSequences < maxSequences
	//		create ephemeralsnake sequence with random:
	//			color
	//			rate
	//			direction
	//			layer
	
	//	for all sequences
	//		if sequence should be destroyed
	//		destroy sequence
	//		rearrange sequences
	
	if (numSequences() < maxSequences)
	{
		int newAddress = numSequences();
		
		Color	tmpColor		= *LITColor.colorList[rand() % 6];
		int		tmpStart		= rand() % 15;
		int		tmpLength		= rand() % 15;
		int		tmpRate			= rand() % 10;
		int		tmpLayer		= rand() % 10;
		bool	tmpDirection	= rand() % 1;
		
		
		sequences[newAddress] = new SeqEphemeralSnake(tmpColor,
													  tmpStart,
													  tmpLength,
													  tmpRate,
													  tmpLayer,
													  tmpDirection);
		
	}
	
	for (int n=0;n<numSequences();n++)
	{
		if (sequences[n]->elements[0]->segments[0]->length == 0)
		{
			delete sequences[n];
			sequences[n] = NULL;
		}
	}
	
	rearrangeSequences();
	
}
