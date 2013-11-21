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
	if (audio.beatJustDetected(2))
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
												&LITColor.blue);
	
	EphemeralSnake* bSnake = new EphemeralSnake(0,
												length,
												down,
												&LITColor.blue);
	
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



RainbowPulser::RainbowPulser()
{
	counter			= 0;
	isIncreasing	= true;
	
	Step<RainbowPulser>* aStep = new Step<RainbowPulser>;
	aStep->fnPtr = &RainbowPulser::drawNewLine;
	addStep(aStep);
}

void RainbowPulser::drawNewLine()
{
	foos.removeAllEntries();
	
	int start;
	
	if (isIncreasing)
	{
		counter++;
		start = 0;
	}
	else
	{
		counter--;
		start = 32-counter;
	}
	
	if (counter == 32)	isIncreasing = false;
	if (counter ==  1)	isIncreasing = true;
	
	RainbowLine* myLine = new RainbowLine(counter,start);
	addFoo(myLine);
}

Alternater::Alternater()
{
//	brightness = 1;
	
	for (int n=0;n<numLEDs;n++)
	{
		float numb = numLEDs;
		float mb = maxBrightness;
		float ratio = n/numb;
		float br = ratio * mb;
		
		addLEDs(LITColor.red, br, n, n);
	}
	
	ListenerFoo* listener = new ListenerFoo();
	addFoo(listener);
}

TestingFoo::TestingFoo()
{
	MovingFoo* aFoo = new MovingFoo();
	
	Step<MovingFoo>* mStep = new Step<MovingFoo>;
	mStep->fnPtr = &MovingFoo::move;
	mStep->period = 20;
	aFoo->addStep(mStep);
	
	aFoo->addLEDs(LITColor.magenta, maxBrightness, 5, 5);
	addFoo(aFoo);
	
	counter = 0;
	
	Step<TestingFoo>* aStep = new Step<TestingFoo>;
	aStep->period = 20;
	aStep->fnPtr = &TestingFoo::checkForSwitch;
	addStep(aStep);
}

void TestingFoo::checkForSwitch()
{
	counter++;
	
	if (counter > 10)
	{
		MovingFoo* myFoo = (MovingFoo*)foos.entry(0)->me;
		myFoo->switchDirection();
		counter = 0;
	}
}

AllWhite::AllWhite()
{
	addLEDs(LITColor.white, maxBrightness, 0, 31);
}


Bunch::Bunch()
{
	MovingFoo* mover = new MovingFoo;
	addFoo(mover);
	
	index = 0;
	
	for (int n=0;n<8;n++)
	{
		mover->addLEDs(*LITColor.colorList[index], maxBrightness, 4*n, 4*n);
	}
	
	Step<MovingFoo>* aStep = new Step<MovingFoo>;
	aStep->period = 2;
	aStep->fnPtr = &MovingFoo::move;
	mover->addStep(aStep);
	
	Step<Bunch>* listen = new Step<Bunch>;
	listen->fnPtr = &Bunch::listenUp;
	addStep(listen);
	
}

void Bunch::listenUp()
{
	if (audio.beatJustDetected(2))
	{
		index = updateValue(index, up, 0, 6, cycles);
		
		for (int n=0;n<foos.entry(0)->me->countLEDs();n++)
		{
			foos.entry(0)->me->fLEDs.entry(n)->me->color.setColor(*LITColor.colorList[index]);
		}
	}
}














































