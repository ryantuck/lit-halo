//	########################################################################

//  Pattern6.cpp

//	3/18/13

//	########################################################################

#include "Pattern6.h"


Pattern6::Pattern6()
{
	//clearSequences();
	createSequencesArray(2);
	
	sequences[0] = new SeqRainbowSnake;
	sequences[1] = new SeqRainbowSnake;
	
	for (int n=0;n<6;n++)
	{
		sequences[1]->elements[0]->segments[n]->start = n+8;
	}
}
