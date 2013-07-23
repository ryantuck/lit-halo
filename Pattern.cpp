//	####################################################################
//
//	LITPattern.cpp
//
//	####################################################################

#include "Pattern.h"

LITPattern::LITPattern()
{
	createThingsArray();
}

LITPattern::~LITPattern()
{
	clearThings();
}

void LITPattern::update()
{
	updateLEDs();
}

void LITPattern::updateLEDs()
{
	for (int t=0;t<numThings();t++)
	{
		things[t]->updateLEDs();
	}	
}

int LITPattern::numThings()
{
	int count = 0;
	for (int n=0;n<8;n++)
		if (things[n] != NULL)
			count++;
	
	return count;
}

void LITPattern::createThingsArray()
{
	things = new Thing*[8];
	
	for (int n=0;n<8;n++) things[n] = NULL;
}

void LITPattern::clearThings()
{
	if (things != NULL)
	{
		for (int n=0;n<8;n++)
		{
			if (things[n] != NULL) delete things[n];
			things[n] = NULL;
		}
		
		delete [] things;
		things = NULL;
	}
}


