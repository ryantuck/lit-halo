//	########################################################################

//  Foo4.cpp

//	7/31/13

//	########################################################################

#include "Foo4.h"

Foo4::Foo4()
{
	addItem();
	
	for (int n=0;n<12;n++)
	{
		foos[0]->addItem();
		foos[0]->setBlock(*LITColor.spectrum[n], maxBrightness, n, n);
	}
	
	addItem();
	
	foos[1]->setBlock(LITColor.cyan, maxBrightness, 15, 29);
	foos[1]->direction = 1;
}

