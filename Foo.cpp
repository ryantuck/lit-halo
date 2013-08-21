//	########################################################################

//  Foo.cpp

//	7/26/13

//	########################################################################

#include "Foo.h"
#include "CustomFoos.h"

//	========================================================

Foo::Foo()
{
	Serial.println("foo constructor");
	
	layer			= 1;
	brightness		= maxBrightness;
	stepIndex		= 0;
	repeats			= true;
	isRunning		= true;
	
	theCurrentStep	= NULL;
}

Foo::~Foo()
{
	Serial.println("foo destructor");
	
	steps.removeAllEntries();
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

template <class T>
void Foo::addStep(Step<T>* aStep)
{
	ListObject<Step<Foo> >* entry = new ListObject<Step<Foo> >;
	
	entry->me = (Step<Foo>*)aStep;
	
	steps.addToEnd(entry);
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
	if (foos.length()) return 1;
	else					return 0;
}

bool Foo::hasLEDs()
{
	if (fLEDs.length()) return 1;
	else					return 0;
}

bool Foo::hasSteps()
{
	if (countSteps())	return 1;
	else				return 0;
}

//	========================================================

void Foo::checkSteps()
{
	theCurrentStep = steps.entry(stepIndex)->me;
	
	if (theCurrentStep->isFinished)
	{
		stepIndex++;
		
		if (stepIndex == countSteps())
		{
			if (repeats)		resetSteps();
			else				isRunning = false;
		}
		else
		{
			theCurrentStep = steps.entry(stepIndex)->me;
		}
		
	}
}

void Foo::resetSteps()
{
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

void Foo::updateFoos()
{
	if (hasFoos())
	{
		for (int n=0;n<countFoos();n++)
			foos.entry(n)->me->update();
	}
}

//	========================================================


//	========================================================

void Foo::printVitals()
{
//	Serial.println("Foo Vitals");
//	Serial.print("number of Foos: "); Serial.println(numberOfFoos);
//	Serial.print("number of LEDs: "); Serial.println(numberOfLEDs);
//	Serial.print("array length:   "); Serial.println(arrayLength);
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

//	========================================================

//	list of possible templates for the addStep function
template void Foo::addStep<StepFoo1>	(Step<StepFoo1>*);
template void Foo::addStep<RainbowFoo>	(Step<RainbowFoo>*);
template void Foo::addStep<LinkedFoo>	(Step<LinkedFoo>*);
template void Foo::addStep<KernFoo>		(Step<KernFoo>*);
template void Foo::addStep<Foo2>		(Step<Foo2>*);
template void Foo::addStep<EventFoo>	(Step<EventFoo>*);
template void Foo::addStep<MovingFoo>	(Step<MovingFoo>*);
template void Foo::addStep<MultipleBouncingFoo> (Step<MultipleBouncingFoo>*);
template void Foo::addStep<OscillatingFoo> (Step<OscillatingFoo>*);
template void Foo::addStep<EMFoo>		(Step<EMFoo>*);
template void Foo::addStep<ChargedFoo>	(Step<ChargedFoo>*);




