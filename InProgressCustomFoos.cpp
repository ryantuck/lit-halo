//	########################################################################

//  InProgressCustomFoos.cpp

//	8/23/13

//	########################################################################

#include "InProgressCustomFoos.h"

MultiParticleEvent::MultiParticleEvent()
{
	Step<MultiParticleEvent>* myStep = new Step<MultiParticleEvent>;
	myStep->fnPtr = &MultiParticleEvent::checkForAllOverlap;
	addStep(myStep);
	
	MovingFoo* aFoo = new MovingFoo;
	MovingFoo* bFoo = new MovingFoo;
	MovingFoo* cFoo = new MovingFoo;
	MovingFoo* dFoo = new MovingFoo;
	
	Color* foosColor = &LITColor.green;
	
	aFoo->addLEDs(*foosColor, maxBrightness, 0, 0);
	bFoo->addLEDs(*foosColor, maxBrightness, 0, 0);
	cFoo->addLEDs(*foosColor, maxBrightness, 0, 0);
	dFoo->addLEDs(*foosColor, maxBrightness, 0, 0);
	
	aFoo->direction = down;
	bFoo->direction = up;
	cFoo->direction = down;
	dFoo->direction = up;
	
	Step<MovingFoo>* aStep = new Step<MovingFoo>;
	Step<MovingFoo>* bStep = new Step<MovingFoo>;
	Step<MovingFoo>* cStep = new Step<MovingFoo>;
	Step<MovingFoo>* dStep = new Step<MovingFoo>;
	
	aStep->fnPtr = &MovingFoo::move;
	bStep->fnPtr = &MovingFoo::move;
	cStep->fnPtr = &MovingFoo::move;
	dStep->fnPtr = &MovingFoo::move;
	
	aStep->period = 1;
	bStep->period = 1;
	cStep->period = 2;
	dStep->period = 2;
	
	aFoo->addStep(aStep);
	bFoo->addStep(bStep);
	cFoo->addStep(cStep);
	dFoo->addStep(dStep);
	
	addFoo(aFoo);
	addFoo(bFoo);
	addFoo(cFoo);
	addFoo(dFoo);
}

void MultiParticleEvent::checkForAllOverlap()
{
	int cAddress = foos.entry(2)->me->fLEDs.entry(0)->me->address;
	
	if (cAddress == 0 && counter > 2) isRunning = false;
	
	counter++;
}

AListener::AListener()
{
	Step<AListener>* aStep = new Step<AListener>;
	aStep->fnPtr = &AListener::listen;
	addStep(aStep);
}

void AListener::listen()
{
	if (audio.beatJustDetected(0))
	{
		PulseFromCenter* a = new PulseFromCenter;
		addFoo(a);
	}
}

PulseFromCenter::PulseFromCenter()
{
	length = 17;
	
	Step<PulseFromCenter>* aStep = new Step<PulseFromCenter>;
	aStep->fnPtr = &PulseFromCenter::checkForLength;
	addStep(aStep);
	
	EphemeralSnake* aSnake = new EphemeralSnake(0,
												length,
												up,
												&LITColor.yellow);
	
	EphemeralSnake* bSnake = new EphemeralSnake(0,
												length,
												down,
												&LITColor.yellow);
	
	addFoo(aSnake);
	addFoo(bSnake);
}

void PulseFromCenter::checkForLength()
{
	if (!hasFoos())	isRunning = false;
}

BandMeter::BandMeter()
{
	length	= 10;
	band	= 0;
	
	Step<BandMeter>* aStep = new Step<BandMeter>;
	aStep->fnPtr = &BandMeter::adjustLengthForAudio;
	addStep(aStep);
}

void BandMeter::adjustLengthForAudio()
{
	int num = length * audio.eq.spectrum[band] / 1023;
	
	fLEDs.removeAllEntries();
	
	for (int n=0;n<num;n++)
	{
		addLEDs(LITColor.lavender, maxBrightness, n,n);
	}
}













