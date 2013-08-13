//	########################################################################

//  EventFoo.cpp

//	7/30/13

//	########################################################################

#include "EventFoo.h"

EventFoo::EventFoo()
{
	killCounter = 0;
	
//	addItem();
//	foos[0]->setBlock(LITColor.red, maxBrightness, 2, 5);
	
	Foo* aFoo = new Foo;
	addFoo(aFoo);
	aFoo->addLEDs(LITColor.red, maxBrightness, 2, 5);
}

void EventFoo::update()
{
	if (hasFoos())
	{
		killCounter++;
		Serial.println(killCounter);
		
		if (killCounter > 60)
			foos.entry(0)->me->readyToDie = 1;
		if (foos.entry(0)->me->readyToDie)
			foos.removeAllEntries();
	}
	
	Serial.print("number of Foos: ");
	Serial.println(countFoos());
}

