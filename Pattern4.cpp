//	########################################################################

//  Pattern4.cpp

//	3/17/13

//	########################################################################

#include "Pattern4.h"

Pattern4::Pattern4()
{
	createSequencesArray(6);
	
	for (int n=0;n<maxSequences;n++)
	{
		sequences[n] = new SeqMovingDot;
		sequences[n]->elements[0]->rate = n;
	}
	
	sequences[0]->elements[0]->segments[0]->color.setColor(LITColor.red);
	sequences[1]->elements[0]->segments[0]->color.setColor(LITColor.yellow);
	sequences[2]->elements[0]->segments[0]->color.setColor(LITColor.green);
	sequences[3]->elements[0]->segments[0]->color.setColor(LITColor.cyan);
	sequences[4]->elements[0]->segments[0]->color.setColor(LITColor.blue);
	sequences[5]->elements[0]->segments[0]->color.setColor(LITColor.magenta);
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