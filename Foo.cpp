//	########################################################################

//  Foo.cpp

//	7/26/13

//	########################################################################

#include "Foo.h"

//	========================================================

Foo::Foo()
{	
	io				= 1;
	period			= 1;
	layer			= 1;
	direction		= 0;
	periodCounter	= 0;
	readyToDie		= 0;
	brightness		= maxBrightness;
}

Foo::~Foo()
{	
	myFooList.removeAllEntries();
	myLEDList.removeAllEntries();
}

//	========================================================

void Foo::addFoo(Foo *aFoo)
{
	ListObject<Foo>* entry = new ListObject<Foo>;
	
	entry->me = aFoo;
	
	myFooList.addToEnd(entry);
}

void Foo::addLED(AddressedLED *aLED)
{
	ListObject<AddressedLED>* entry = new ListObject<AddressedLED>;
	
	entry->me = aLED;
	
	myLEDList.addToEnd(entry);
}

void Foo::addLEDs(Color aColor, int aBrightness, int aStart, int aEnd)
{
	// check values
	if (aStart	< 0)			aStart	= 0;
	if (aStart	>= numLEDs)		aStart	= numLEDs;
	if (aEnd	< 0)			aEnd	= 0;
	if (aEnd	>= numLEDs)		aEnd	= numLEDs;
	
	int length = aEnd-aStart+1;
	
	for (int n=0;n<length;n++)
	{
		AddressedLED* aLED = new AddressedLED;
		aLED->color.setColor(aColor);
		aLED->brightness = aBrightness;
		aLED->address = aStart + n;
		
		addLED(aLED);
	}
}

int Foo::countFoos()
{
	return myFooList.length();
}

int Foo::countLEDs()
{
	return myLEDList.length();
}

bool Foo::hasFoos()
{
	if (myFooList.length()) return 1;
	else					return 0;
}

bool Foo::hasLEDs()
{
	if (myLEDList.length()) return 1;
	else					return 0;
}

//	========================================================

void Foo::iterate()
{
	checkForUpdate();
	updateFoos();
	updateLEDs();
}

void Foo::update()
{
	move(direction);
}

void Foo::updateLEDs()
{
	if (io)
	{
		if (hasLEDs())
		{
			for (int n=0;n<countLEDs();n++)
			{
				int addr = myLEDList.entry(n)->me->address;
				
				if (layer > leds[addr].layer)
				{
					leds[addr].setAttributes(*myLEDList.entry(n)->me);
					leds[addr].layer = layer;
				}
				else if (layer == leds[addr].layer)
				{
					myLEDList.entry(n)->me->brightness = brightness;
					leds[addr].mixWith(*myLEDList.entry(n)->me);
					leds[addr].adjustColor();
				}
			}
		}
	}
}

void Foo::updateFoos()
{
	for (int n=0;n<countFoos();n++) myFooList.entry(n)->me->iterate();
}

void Foo::checkForUpdate()
{
	periodCounter++;
	
	if (canUpdate())
	{
		update();
		periodCounter = 0;
	}
}

//	========================================================

void Foo::move(bool direction)
{
	for (int n=0;n<countLEDs();n++)
	{
		byte addr = myLEDList.entry(n)->me->address;
		addr = updateValue(addr, direction, 0, 31, 1);
		myLEDList.entry(n)->me->address = addr;
	}
}

//	========================================================

byte Foo::updateValue(byte parameter,
					  bool direction,
					  byte minVal,
					  byte maxVal,
					  bool cycles)
{
	if (direction)
	{
		if (parameter == maxVal)
		{
			if (cycles) parameter = minVal;
			else		parameter = maxVal;
		}
		else parameter++;
	}
	else
	{
		if (parameter == minVal)
		{
			if (cycles)	parameter = maxVal;
			else		parameter = minVal;
		}
		else parameter--;
	}
	
	return parameter;
}

bool Foo::canUpdate()
{
	if (periodCounter >= period)	return 1;
	else							return 0;
}


void Foo::printVitals()
{
//	Serial.println("Foo Vitals");
//	Serial.print("number of Foos: "); Serial.println(numberOfFoos);
//	Serial.print("number of LEDs: "); Serial.println(numberOfLEDs);
//	Serial.print("array length:   "); Serial.println(arrayLength);
}

void Foo::switchDirection()
{
	if (direction)	direction = 0;
	else			direction = 1;
}

void Foo::merge(Foo *aFoo)
{
//	for (int n=0;n<aFoo->numberOfLEDs;n++)
//	{
//		setBlock(aFoo->fLEDs[n]->color,
//				 maxBrightness,
//				 aFoo->fLEDs[n]->address,
//				 aFoo->fLEDs[n]->address);
//	}
//	
//	for (int n=0;n<numberOfFoos;n++)
//	{
//		addItem();
//		foos[n]->addItem();
//		foos[n]->merge(aFoo->foos[n]);
//	}
//	
//	if (aFoo->direction != direction)
//	{
//		if (aFoo->period < period)
//		{
//			direction = aFoo->direction;
//		}
//	}
}
















