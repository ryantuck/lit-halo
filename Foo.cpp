//	########################################################################

//  Foo.cpp

//	7/26/13

//	########################################################################

#include "Foo.h"
#include "CustomFoos.h"

//	========================================================

Foo::Foo()
{	
	io				= 1;
	period			= 1;
	layer			= 1;
	direction		= 0;
	periodCounter	= 0;
	readyToDie		= false;
	brightness		= maxBrightness;
	currentStep		= 0;
	isRecurring		= true;
	isRunning		= true;
}

Foo::~Foo()
{	
	foos.removeAllEntries();
	fLEDs.removeAllEntries();
}

//	========================================================

void Foo::addFoo(Foo *aFoo)
{
	ListObject<Foo>* entry = new ListObject<Foo>;
	
	entry->me = aFoo;
	
	foos.addToEnd(entry);
}

void Foo::addLED(AddressedLED *aLED)
{
	ListObject<AddressedLED>* entry = new ListObject<AddressedLED>;
	
	entry->me = aLED;
	
	fLEDs.addToEnd(entry);
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
	return foos.length();
}

int Foo::countLEDs()
{
	return fLEDs.length();
}

bool Foo::hasFoos()
{
	if (foos.length()) return 1;
	else					return 0;
}

bool Foo::hasLEDs()
{
	if (fLEDs.length()) return 1;
	else					return 0;
}

//	========================================================

int Foo::countSteps()
{
	return steps.length();
}

bool Foo::hasSteps()
{
	if (countSteps())	return 1;
	else				return 0;
}

void Foo::checkSteps()
{
	if (steps.entry(currentStep)->me->isFinished)
	{
		currentStep++;
		
		if (currentStep == countSteps())
		{
			if (isRecurring)	resetSteps();
			else				isRunning = false;
		}
	}
}

void Foo::resetSteps()
{
	currentStep = 0;
	
	for (int n=0;n<countSteps();n++)
	{
		steps.entry(n)->me->currentCount	= 0;
		steps.entry(n)->me->isFinished		= false;
	}
}

void Foo::doAFunction(ListObject<Step<Foo> > *obj)
{
	(*this.*obj->me->fnPtr)();
}

void Foo::updateSteps()
{
	if (isRunning)
	{
		if (hasSteps())
		{
			steps.entry(currentStep)->me->periodCounter++;
			
			if (steps.entry(currentStep)->me->canUpdate())
			{
				doAFunction(steps.entry(currentStep));
				steps.entry(currentStep)->me->iterate();
				checkSteps();
			}
		}
	}
}

template <class T>
void Foo::addStep(Step<T>* aStep)
{
	ListObject<Step<Foo>>* entry = new ListObject<Step<Foo>>;
	
	entry->me = (Step<Foo>*)aStep;
	
	steps.addToEnd(entry);
}

//	========================================================

void Foo::iterate()
{
	//checkForUpdate();
	updateSteps();
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
				int addr = fLEDs.entry(n)->me->address;
				
				if (layer > leds[addr].layer)
				{
					leds[addr].setAttributes(*fLEDs.entry(n)->me);
					leds[addr].layer = layer;
				}
				else if (layer == leds[addr].layer)
				{
					fLEDs.entry(n)->me->brightness = brightness;
					leds[addr].mixWith(*fLEDs.entry(n)->me);
					leds[addr].adjustColor();
				}
			}
		}
	}
}

void Foo::updateFoos()
{
	for (int n=0;n<countFoos();n++) foos.entry(n)->me->iterate();
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
		byte addr = fLEDs.entry(n)->me->address;
		addr = updateValue(addr, direction, 0, 31, 1);
		fLEDs.entry(n)->me->address = addr;
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
	Serial.print("direction: ");
	Serial.println(direction);
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

void Foo::printTest()
{
	Serial.println("printing");
}

//	list of possible templates for the createStep function
//template Step<StepFoo1>* Foo::createStep<StepFoo1>();

template void Foo::addStep<StepFoo1>(Step<StepFoo1>*);









