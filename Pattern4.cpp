//	########################################################################

//  Pattern4.cpp

//	3/17/13

//	########################################################################

#include "Pattern4.h"

Pattern4::Pattern4()
{
	clearSequences();
	createSequencesArray(6);
	
	for (int n=0;n<maxSequences;n++)
	{
		sequences[n] = new SeqMovingDot(*LITColor.colorList[n],n);
		sequences[n]->elements[0]->rate = n*4;
	}
}

void Pattern4::update()
{
	for (int n=0;n<maxSequences;n++)
	{
		if (sequences[n]->elements[0]->canUpdate())
		{
			sequences[n]->elements[0]->move(n % 2);
		}
		
		sequences[n]->update();
	}
}