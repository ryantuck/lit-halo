//	########################################################################

//  SparkleThing.cpp

//	7/23/13

//	########################################################################

#include "SparkleThing.h"

SparkleThing::SparkleThing()
{
	
}

void SparkleThing::update()
{
	clear();
	
	for (int n=0;n<12;n++)
	{
		int tmp = rand()%32;
		
		setBlock(LITColor.white, maxBrightness, tmp, tmp);
	}
}


