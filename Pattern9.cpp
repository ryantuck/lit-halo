//
//  Pattern9.cpp
//  LIT-Source
//
//  Created by Ryan Tuck on 3/23/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "Pattern9.h"

Pattern9::Pattern9()
{
	createSequencesArray(2);
}

void Pattern9::update()
{
	
	if (audio->checkForBeat(1))
	{
		if (numSequences() == 0)
		{
			Color tmpColor = *LITColor.colorList[rand()%7];
			
			sequences[0] = new SeqEphemeralSnake(tmpColor,
												 0,8,1,1,1);
			sequences[1] = new SeqEphemeralSnake(tmpColor,
												 15,8,1,1,0);
			
			linkUp();
		}
	}
	
	for (int n=0;n<numSequences();n++)
	{
		if (sequences[n]->io == 0)
		{
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