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


MovingSwitcher::MovingSwitcher()
{
	MovingFoo* mover = new MovingFoo;
	addFoo(mover);
	
	mover->addLEDs(LITColor.magenta, maxBrightness, 0, 0);
	
	Step<MovingFoo>* moveStep = new Step<MovingFoo>;
	moveStep->period = 2;
	moveStep->fnPtr = &MovingFoo::move;
	mover->addStep(moveStep);
	
	Step<MovingSwitcher>* listen = new Step<MovingSwitcher>;
	listen->fnPtr = &MovingSwitcher::listenUp;
	addStep(listen);
}

void MovingSwitcher::listenUp()
{
	if (audio.beatJustDetected(3))
	{
		MovingFoo* mfPtr = (MovingFoo*)foos.entry(0)->me;
		mfPtr->switchDirection();		
	}
}

BrightnessFrequency::BrightnessFrequency()
{
	band = 2;
	start = 0;
	
	for (int n=0;n<8;n++)
	{
		addLEDs(LITColor.green, maxBrightness, 4*n+start, 4*n+start);
	}
	
	Step<BrightnessFrequency>* aStep = new Step<BrightnessFrequency>;
	aStep->fnPtr = &BrightnessFrequency::listenUp;
	addStep(aStep);
}

BrightnessFrequency::BrightnessFrequency(int aBand,Color aColor,int aStart)
{
	band = aBand;
	start = aStart;
	
	for (int n=0;n<8;n++)
	{
		addLEDs(aColor, maxBrightness, 4*n+start, 4*n+start);
	}
	
	Step<BrightnessFrequency>* aStep = new Step<BrightnessFrequency>;
	aStep->fnPtr = &BrightnessFrequency::listenUp;
	addStep(aStep);
	
}

void BrightnessFrequency::listenUp()
{
	float val = (float)audio.eq.spectrum[band];
	
	float max = 1024 - (float)audio.baseline(band, audio.pot.currentValue);
	
	float pct = val/max;
	
	float br = pct*100;

	for (int n=0;n<countLEDs();n++)
	{
		fLEDs.entry(n)->me->brightness = br;
	}
}

BF4::BF4()
{
	BrightnessFrequency* bf2 = new BrightnessFrequency(2,LITColor.red,0);
	BrightnessFrequency* bf3 = new BrightnessFrequency(3,LITColor.yellow,1);
	BrightnessFrequency* bf4 = new BrightnessFrequency(4,LITColor.green,2);
	BrightnessFrequency* bf5 = new BrightnessFrequency(5,LITColor.cyan,3);
	
	addFoo(bf2);
	addFoo(bf3);
	addFoo(bf4);
	addFoo(bf5);
}

BattChecker::BattChecker()
{
	
}

void BattChecker::checkBatt()
{
	
}

BinaryValue::BinaryValue()
{
	val = 0;
	start = 0;
	
	for (int n=0;n<10;n++)
	{
		int addr = start+n;
		
		addLEDs(LITColor.red, maxBrightness,addr,addr);
	}
	
	Step<BinaryValue>* myStep = new Step<BinaryValue>;
	myStep->fnPtr = &BinaryValue::display;
	myStep->period = 4;
	addStep(myStep);
}

BinaryValue::BinaryValue(int aStart)
{
	val = 0;
	start = aStart;
	
	for (int n=0;n<10;n++)
	{
		int addr = start+n;
		
		addLEDs(LITColor.red, maxBrightness,addr,addr);
	}
	
	Step<BinaryValue>* myStep = new Step<BinaryValue>;
	myStep->fnPtr = &BinaryValue::display;
	myStep->period = 4;
	addStep(myStep);
}

void BinaryValue::display()
{
	changeLEDs(val);
}

void BinaryValue::cycle()
{
	changeLEDs(val);
	val++;
	if (val >= 1024) val = 0;
}

void BinaryValue::changeLEDs(int newVal)
{
	// first set all LEDs to red (0)
	for (int n=0;n<countLEDs();n++)
	{
		fLEDs.entry(n)->me->color.setColor(LITColor.red);
	}
	
	
	// then go through newVal and change to green if 1
	for (int n=0;n<countLEDs();n++)
	{
		int threshold = pow(2,9-n);
		
		if (newVal >= threshold)
		{
			fLEDs.entry(n)->me->color.setColor(LITColor.green);
			newVal -= threshold;
		}
	}
}

DoubleMonitor::DoubleMonitor()
{
	Step<DoubleMonitor>* myStep = new Step<DoubleMonitor>;
	myStep->fnPtr = &DoubleMonitor::checkValues;
	myStep->period = 200;
	addStep(myStep);
	
	BinaryValue* battMonitor = new BinaryValue(0);
	BinaryValue* voltMonitor = new BinaryValue(16);
	
	addFoo(battMonitor);
	addFoo(voltMonitor);
		
}

void DoubleMonitor::checkValues()
{
	int battVoltage = analogRead(0);
	int threeV = analogRead(7);
	
	BinaryValue* bPtr = (BinaryValue*)foos.entry(0)->me;
	BinaryValue* vPtr = (BinaryValue*)foos.entry(1)->me;
	
	bPtr->val = battVoltage;
	vPtr->val = threeV;
}
































