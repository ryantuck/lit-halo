//	########################################################################

//  Pattern5.cpp

//	3/17/13

//	########################################################################

#include "Pattern5.h"

Pattern5::Pattern5()
{
	//clearSequences();
	createSequencesArray(3);
	
	//	don't need to create any sequences here.
	//	they will be created in the update() function.
}

void Pattern5::update()
{
	//	could benefit from another condition to be met (audio, etc)
	
	if (numSequences() < maxSequences && rand() % 4 == 1)
	{
		Serial.println("created");
		
		int newAddress = numSequences();
		
		Color	tmpColor		= *LITColor.colorList[rand() % 6];
		int		tmpStart		= rand() % 15;
		int		tmpLength		= 5;
		int		tmpRate			= 4;
		int		tmpLayer		= rand() % 10 + 1;
		bool	tmpDirection	= rand() % 2;
		
		
		sequences[newAddress] = new SeqEphemeralSnake(tmpColor,
													  tmpStart,
													  tmpLength,
													  tmpRate,
													  tmpLayer,
													  tmpDirection);
		
		linkUp();
		
	}
	
	for (int n=0;n<numSequences();n++)
	{
		if (sequences[n]->io == 0)
		{
			Serial.println("deleted");
			delete sequences[n];
			sequences[n] = NULL;
			rearrangeSequences();
		}
	}
	
	for (int n=0;n<numSequences();n++)
	{
		sequences[n]->update();
	}
	
}
