//	########################################################################

//  BounceFoo.cpp

//	7/31/13

//	########################################################################

#include "BounceFoo.h"

BounceFoo::BounceFoo()
{
	counter = 0;
	
	addItem();
	addItem();
	
	foos[0]->setBlock(LITColor.red, maxBrightness, 1, 4);
	foos[1]->setBlock(LITColor.blue, maxBrightness, 5, 8);
	
	foos[0]->direction = 0;
	foos[1]->direction = 1;
}

void BounceFoo::update()
{
	counter++;
	
	if (counter == 13)
	{
		if (foos[0]->direction == 0)
		{
			foos[0]->direction = 1;
			foos[1]->direction = 0;
		}
		else
		{
			foos[0]->direction = 0;
			foos[1]->direction = 1;
		}
		
		
		counter = 0;
	}
}

