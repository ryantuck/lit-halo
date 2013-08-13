//	########################################################################

//  RainbowFoo.cpp

//	7/31/13

//	########################################################################

#include "RainbowFoo.h"

RainbowFoo::RainbowFoo()
{
	addItem();
	addItem();
	
	for (int n=0;n<12;n++)
	{
		foos[0]->addItem();
		foos[0]->setBlock(*LITColor.spectrum[n], maxBrightness, n, n);
		
		foos[1]->addItem();
		foos[1]->setBlock(*LITColor.spectrum[n], maxBrightness, n+16,n+16);
		
		foos[0]->direction = 0;
		foos[1]->direction = 1;
	}
}

