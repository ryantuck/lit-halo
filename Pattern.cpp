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
	for (int l=0;l<numLEDs;l++)
	{
		int tmpLayer = 0;
		
		for (int t=0;t<numThings();t++)
		{
			if (!things[t]->tLEDs[l].color.isBlack())
			{
				if (things[t]->layer > tmpLayer)
				{
					tmpLayer = things[t]->layer;
					
					leds[l].setAttributes(things[t]->tLEDs[l]);
					leds[l].layer = tmpLayer;
				}
				else if (things[t]->layer == tmpLayer)
				{
					leds[l].mixWith(things[t]->tLEDs[l]);
					leds[l].layer = tmpLayer;
					
					//  mix colors
					//leds[l].color.mixWith(things[t]->tLEDs[l].color);
					
					leds[l].adjustColor();
				}
			}
		}
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


