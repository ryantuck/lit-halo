//	########################################################################

//  Pattern7.cpp

//	3/22/13

//	########################################################################

#include "Pattern7.h"

Pattern7::Pattern7()
{
	//clearSequences();
	createSequencesArray(4);
	
	sequences[0] = new SeqMovingDot(LITColor.red,0);
	sequences[1] = new SeqMovingDot(LITColor.green,7);
	sequences[2] = new SeqMovingDot(LITColor.blue,8);
	sequences[3] = new SeqMovingDot(LITColor.yellow,15);
	
	for (int n=0;n<maxSequences;n++)
	{
		sequences[n]->elements[n]->rate = 5;
	}
}

void Pattern7::update()
{
	for (int n=0;n<maxSequences;n++)
	{
		if (sequences[n]->elements[0]->canUpdate())
		{
			sequences[n]->elements[0]->move((n+1)%2);
		}
		
		sequences[n]->update();
	}
}