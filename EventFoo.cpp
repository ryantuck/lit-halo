//	########################################################################

//  EventFoo.cpp

//	7/30/13

//	########################################################################

#include "EventFoo.h"

EventFoo::EventFoo()
{
	killCounter = 0;

	Foo* aFoo = new Foo;
	addFoo(aFoo);
	aFoo->addLEDs(LITColor.red, maxBrightness, 2, 5);
	
	Step<EventFoo>* aStep = new Step<EventFoo>;
	
	aStep->fnPtr = &EventFoo::moveLeft;
	aFoo->addStep(aStep);
	
	aStep->count = 50;
	
	aFoo->isRecurring = false;
}

//void EventFoo::update()
//{
//	if (hasFoos())
//	{
//		killCounter++;
//		Serial.println(killCounter);
//		
//		if (killCounter > 60)
//			foos.entry(0)->me->readyToDie = 1;
//		if (foos.entry(0)->me->readyToDie)
//			foos.removeAllEntries();
//	}
//	
//	Serial.print("number of Foos: ");
//	Serial.println(countFoos());
//}

void EventFoo::moveLeft()
{
	move(1);
}