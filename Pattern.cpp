//	####################################################################
//
//	Pattern.cpp
//
//	####################################################################

#include "Pattern.h"

Pattern::Pattern()
{
	createThingsArray();
}

Pattern::~Pattern()
{
	clearThings();
}

void Pattern::update()
{
	updateLEDs();
}

void Pattern::updateLEDs()
{
	Serial.print("num things: "); Serial.println(numThings());
	
	for (int l=0;l<numLEDs;l++)
	{
		int tmpLayer = 0;
		
		for (int t=0;t<numThings();t++)
		{
			Serial.print(l); Serial.print(" "); Serial.println(t);
			
			if (!things[t]->tLEDs[l].color.isBlack())
			{
				if (things[t]->layer > tmpLayer)
				{
					tmpLayer = things[t]->layer;
					
					leds[l].set(things[t]->tLEDs[l]);
				}
				else if (things[t]->layer == tmpLayer)
				{
					//leds[l].set(things[t]->tLEDs[l]);
					
					//  mix colors
					leds[l].color.mixWith(things[t]->tLEDs[l].color);
					//leds[l].brightness = (leds[l].brightness + things[t]->tLEDs[l].brightness) / 2;	//ok?
					//leds[l].adjustColor();
				}
			}
		}
	}
}

int Pattern::numThings()
{
	int count = 0;
	for (int n=0;n<8;n++)
		if (things[n] != NULL)
			count++;
	
	return count;
}

void Pattern::createThingsArray()
{
	things = new Thing*[8];
	
	for (int n=0;n<8;n++) things[n] = NULL;
}

void Pattern::clearThings()
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


