//	########################################################################

//  Foo.cpp

//	7/26/13

//	########################################################################

#include "Foo.h"

//	========================================================

Foo::Foo()
{
	layer			= 1;
	brightness		= maxBrightness;
	stepIndex		= 0;
	repeats			= true;
	isRunning		= true;
	
	theCurrentStep	= NULL;
}

Foo::~Foo()
{
	steps.removeAllEntries();
	foos.removeAllEntries();
	fLEDs.removeAllEntries();
}

//	========================================================

void Foo::addFoo(Foo *aFoo)
{
	// adds a foo to the foos list
	ListObject<Foo>* entry = new ListObject<Foo>;
	entry->me = aFoo;
	foos.addToEnd(entry);
}

void Foo::addLED(AddressedLED *aLED)
{
	// adds an LED to the LED list
	// LED is 'addressed' because it needs to retain this info.
	ListObject<AddressedLED>* entry = new ListObject<AddressedLED>;
	entry->me = aLED;
	fLEDs.addToEnd(entry);
}

void Foo::addLEDs(Color aColor, int aBrightness, int aStart, int aEnd)
{
	// check values - should create a fucntion that does this
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

//	========================================================

int Foo::countFoos()
{
	return foos.length();
}

int Foo::countLEDs()
{
	return fLEDs.length();
}

int Foo::countSteps()
{
	return steps.length();
}

bool Foo::hasFoos()
{
	if (foos.length())	return 1;
	else				return 0;
}

bool Foo::hasLEDs()
{
	if (fLEDs.length()) return 1;
	else				return 0;
}

bool Foo::hasSteps()
{
	if (countSteps())	return 1;
	else				return 0;
}

//	========================================================

void Foo::checkSteps()
{
	// checks steps to see whether they have run their course.
	// if a step is done running, next step is selected as current.
	
	theCurrentStep = steps.entry(stepIndex)->me;
	
	if (theCurrentStep->isFinished)
	{
		stepIndex++;
		
		if (stepIndex == countSteps())
		{
			if (repeats)	resetSteps();
			else			isRunning = false;
		}
		else
		{
			theCurrentStep = steps.entry(stepIndex)->me;
		}
	}
}

void Foo::resetSteps()
{
	// resets all step counts to zero for a certain foo.
	
	stepIndex = 0;
	theCurrentStep = steps.entry(stepIndex)->me;
	for (int n=0;n<countSteps();n++)
	{
		steps.entry(n)->me->currentCount	= 0;
		steps.entry(n)->me->isFinished		= false;
	}
}

void Foo::execute(ListObject<Step<Foo> > *obj)
{
	// enables a step to execute its fnPtr function.
	(*this.*obj->me->fnPtr)();
}

//	========================================================

void Foo::update()
{
	updateSteps();
	updateFoos();
	updateLEDs();
}

void Foo::updateSteps()
{
	if (isRunning)
	{
		if (hasSteps())
		{
			theCurrentStep = steps.entry(stepIndex)->me;
			theCurrentStep->periodCounter++;
			
			if (theCurrentStep->canUpdate())
			{
				execute(steps.entry(stepIndex));
				theCurrentStep->iterate();
				checkSteps();
			}
		}
	}
}

void Foo::updateLEDs()
{
	// goes through foos LEDs and updates meta-LED array.
	// either overwrites, mixes, or ignores depending on layers.
	
	if (hasLEDs())
	{
		for (int n=0;n<countLEDs();n++)
		{
			int addr = fLEDs.entry(n)->me->address;

			if (layer > leds[addr].layer)
			{
				leds[addr].setAttributes(*fLEDs.entry(n)->me);
				leds[addr].layer = layer;
			}
			else if (layer == leds[addr].layer)
			{
				//fLEDs.entry(n)->me->brightness = brightness;
				leds[addr].mixWith(*fLEDs.entry(n)->me);
				leds[addr].adjustColor();
			}
			
			// ok patch for now, but brightness adjustments
			// should be taken care of elsewhere
			leds[addr].adjustColor();
		}
	}
}

void Foo::updateFoos()
{
	// iterates through child foos and checks if they're running
	// if one has stopped running, it's removed from the foo list.
	
	if (hasFoos())
	{
		int index = 0;
		
		while (index < countFoos())
		{
			if (foos.entry(index)->me->isRunning)
			{
				foos.entry(index)->me->update();
				index++;
			}
			else
			{
				foos.removeEntry(index);
			}
		}
	}
}

//	========================================================

void Foo::merge(Foo *aFoo)
{
	// was thinking of including this at one point. 
}






