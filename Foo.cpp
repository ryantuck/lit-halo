//	########################################################################

//  Foo.cpp

//	7/26/13

//	########################################################################

#include "Foo.h"
#include "CustomFoos.h"

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
template void Foo::addStep<EphemeralSnake> (Step<EphemeralSnake>*);
template void Foo::addStep<EphemeralSnakesFoo> (Step<EphemeralSnakesFoo>*);
template void Foo::addStep<EvenEphemSnakes> (Step<EvenEphemSnakes>*);
template void Foo::addStep<RainbowPulser> (Step<RainbowPulser>*);
template void Foo::addStep<ListenerFoo> (Step<ListenerFoo>*);
template void Foo::addStep<MultiParticleEvent> (Step<MultiParticleEvent>*);
template void Foo::addStep<AListener> (Step<AListener>*);
template void Foo::addStep<PulseFromCenter> (Step<PulseFromCenter>*);








