//	########################################################################

//  EventFoo.cpp

//	7/30/13

//	########################################################################

#include "EventFoo.h"

EventFoo::EventFoo()
{
	killCounter = 0;
	
	addItem();
	foos[0]->setBlock(LITColor.red, maxBrightness, 2, 5);
}

void EventFoo::update()
{
	if (foos)
	{
		updateFoos();
		updateLEDs();
		killCounter++;
		Serial.println(killCounter);
		
		if (killCounter > 60) foos[0]->readyToDie = 1;
		
		
		if (foos[0]->readyToDie)
		{
			destroyArray();
		}
	}
	
}

