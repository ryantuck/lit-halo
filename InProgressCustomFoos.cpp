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

DoubleRainbow::DoubleRainbow()
{
	RainbowLine* r1 = new RainbowLine(16,0);
	RainbowLine* r2 = new RainbowLine(16,16);
	
	addFoo(r1);
	addFoo(r2);
}

BackgroundStepper::BackgroundStepper()
{
	for (int n=0;n<8;n++)
	{
		addLEDs(LITColor.green, maxBrightness, n*4, n*4);
	}
	
	for (int n=0;n<5;n++)
	{
		int x = pow(2,n);
		
		Step<MovingFoo>* moveL = new Step<MovingFoo>;
		moveL->fnPtr = &MovingFoo::moveLeft;
		moveL->count = x;
		addStep(moveL);
		
		Step<MovingFoo>* moveR = new Step<MovingFoo>;
		moveR->fnPtr = &MovingFoo::moveLeft;
		moveR->count = x;
		addStep(moveR);
	}
}


Sparkle::Sparkle()
{
	index = 0;
	
	Serial.println("Sparkle constructor");
	for (int n=0;n<6;n++)
	{
		int x = rand()%32;
		addLEDs(LITColor.white, maxBrightness, x, x);
	}
	
	Step<Sparkle>* flicker = new Step<Sparkle>;
	flicker->fnPtr = &Sparkle::flicker;
	flicker->period = 2;
	addStep(flicker);
	
//	Step<Sparkle>* change = new Step<Sparkle>;
//	change->fnPtr = &Sparkle::changeColor;
//	addStep(change);
}

void Sparkle::flicker()
{
	for (int n=0;n<countLEDs();n++)
	{
		fLEDs.entry(n)->me->address = rand()%32;
	}
	
	if (audio.beatJustDetected(2))
	{
		index = updateValue(index, up, 0, 6, cycles);
		
		for (int n=0;n<countLEDs();n++)
		{
			fLEDs.entry(n)->me->color.setColor(*LITColor.colorList[index]);
		}
	}
}
void Sparkle::changeColor()
{
	if (audio.beatJustDetected(2))
	{
		index = updateValue(index, up, 0, 6, cycles);
		
		for (int n=0;n<countLEDs();n++)
		{
			fLEDs.entry(n)->me->color.setColor(*LITColor.colorList[index]);
		}
	}
}

Pulsater::Pulsater()
{
	for (int n=0;n<8;n++)
	{
		addLEDs(LITColor.white, 0, 4*n, 4*n);
	}
	
	Step<Pulsater>* upStep = new Step<Pulsater>;
	upStep->fnPtr = &Pulsater::upBrightness;
	upStep->count = 100;
	addStep(upStep);
	
	Step<Pulsater>* downStep = new Step<Pulsater>;
	downStep->fnPtr = &Pulsater::downBrightness;
	downStep->count = 100;
	addStep(downStep);
}

void Pulsater::upBrightness()
{
	for (int n=0;n<countLEDs();n++)
	{
		byte x = fLEDs.entry(n)->me->brightness;
		x = updateValue(x, up, 0, maxBrightness, !cycles);
		fLEDs.entry(n)->me->brightness = x;
	}
}

void Pulsater::downBrightness()
{
	for (int n=0;n<countLEDs();n++)
	{
		byte x = fLEDs.entry(n)->me->brightness;
		x = updateValue(x, down, 0, maxBrightness, !cycles);
		fLEDs.entry(n)->me->brightness = x;
	}
}

ListenerWithBunch::ListenerWithBunch()
{
	Step<ListenerWithBunch>* myStep = new Step<ListenerWithBunch>;
	myStep->fnPtr = &ListenerWithBunch::listenUp;
	addStep(myStep);
}

void ListenerWithBunch::listenUp()
{
	if (audio.beatJustDetected(1))
	{
		FiniteBunch* fb = new FiniteBunch;
		addFoo(fb);
	}
}

FiniteBunch::FiniteBunch()
{
	for (int n=0;n<8;n++)
	{
		addLEDs(LITColor.white, maxBrightness, 4*n, 4*n);
	}
	
	layer = 2;
	
	repeats = false;
	
	Step<MovingFoo>* myStep = new Step<MovingFoo>;
	myStep->fnPtr = &MovingFoo::move;
	myStep->count = 32;
	addStep(myStep);
}

DRwithListener::DRwithListener()
{
	DoubleRainbow* dr = new DoubleRainbow;
	addFoo(dr);
	
	ListenerWithBunch* lb = new ListenerWithBunch;
	addFoo(lb);
}

SparkleWithListener::SparkleWithListener()
{
	Serial.println("SparkleWithListener constructor");
	
	Serial.println(countSteps());
	
	Step<SparkleWithListener>* aStep = new Step<SparkleWithListener>;
	aStep->fnPtr = &SparkleWithListener::changeColor;
	addStep(aStep);
	
	Serial.println(countSteps());
	
	index = 0;
}

void SparkleWithListener::changeColor()
{
	Serial.println(" in changeColor");
	
	if (audio.beatJustDetected(2))
	{
		index = updateValue(index, up, 0, 6, cycles);
		
		for (int n=0;n<countLEDs();n++)
		{
			
			fLEDs.entry(n)->me->color.setColor(*LITColor.colorList[index]);
		}
	}
}

BigAudioTester::BigAudioTester()
{
	audio.pot.update(1);
	
	count = 0;
	rollingIndex = 0;
	
	for (int n=0;n<7;n++)
	{
		spectrumData[n] = 0;
	}
	
	Foo* whiteFoo = new Foo;
	whiteFoo->addLEDs(LITColor.white, maxBrightness, 0, 31);
	addFoo(whiteFoo);

//	Foo* whiteDot = new Foo;
//	for (int n=0;n<16;n++)
//	{
//		whiteDot->addLEDs(LITColor.white, maxBrightness, 2*n,2*n);
//	}
//	addFoo(whiteDot);
	
	
	Step<BigAudioTester>* collect = new Step<BigAudioTester>;
	collect->fnPtr = &BigAudioTester::collect1KDataPoints;
	collect->count = 1000;
	addStep(collect);
	
	Step<BigAudioTester>* setUp = new Step<BigAudioTester>;
	setUp->fnPtr = &BigAudioTester::setUpLEDs;
	setUp->count = 1;
	addStep(setUp);
	
	Step<BigAudioTester>* show = new Step<BigAudioTester>;
	show->fnPtr = &BigAudioTester::displayData;
	addStep(show);
	
	
}

void BigAudioTester::setUpLEDs()
{
	foos.removeAllEntries();
	
	BinaryValue* spectrumAvg	= new BinaryValue(0);
	BinaryValue* currentIndex	= new BinaryValue(16);
	
	addFoo(currentIndex);
	addFoo(spectrumAvg);
}

void BigAudioTester::collect1KDataPoints()
{
	count++;
	
	for (int n=0;n<7;n++)
	{
		int x = spectrumData[n];
		
		x += (audio.eq.spectrum[n] - x)/count;
		
		spectrumData[n] = x;
	}
}

void BigAudioTester::displayData()
{
	BinaryValue* bvIndex = (BinaryValue*)foos.entry(0)->me;
	BinaryValue* bvValue = (BinaryValue*)foos.entry(1)->me;
	
	bvIndex->val = rollingIndex;
	bvValue->val = spectrumData[rollingIndex];
	
	
	Serial.println(rollingIndex);
	serialPrintData();
	rollingIndex = updateValue(rollingIndex, up, 0, 6, cycles);
	
	delay(5000);
}

void BigAudioTester::serialPrintData()
{
	for (int n=0;n<7;n++)
	{
		Serial.print(spectrumData[n]);
		Serial.print(" ");
	}
	Serial.println();
}



BinaryTester::BinaryTester()
{
	// created to test if binary value is working properly
	// turns out it does.
	
	number = 1;
	
	BinaryValue* bv = new BinaryValue(6);
	addFoo(bv);
	
	Step<BinaryTester>* st = new Step<BinaryTester>;
	st->fnPtr = &BinaryTester::increment;
	addStep(st);
}

void BinaryTester::increment()
{
	BinaryValue* bvPtr = (BinaryValue*)foos.entry(0)->me;
	bvPtr->val = number;
	Serial.println(number);
	number = updateValue(number, up, 1, 16, cycles);
	delay(2000);
}



VarianceTester::VarianceTester(int aBand)
{
	for (int n=0;n<100;n++)
		dataPoints[n] = 0;
	
	variance	= 0;
	index		= 0;
	avg			= 0;
	band		= aBand;
	
	Step<VarianceTester>* inc = new Step<VarianceTester>;
	inc->fnPtr = &VarianceTester::increment;
	inc->count = 100;
	addStep(inc);
	
	Step<VarianceTester>* comp = new Step<VarianceTester>;
	comp->fnPtr = &VarianceTester::computeVariance;
	comp->count = 1;
	addStep(comp);
	
	Step<VarianceTester>* res = new Step<VarianceTester>;
	res->fnPtr = &VarianceTester::resetValues;
	res->count = 1;
	addStep(res);
	
}

void VarianceTester::increment()
{
	dataPoints[index] = audio.eq.spectrum[band];
	
	Serial.print(index); Serial.print(" ");
	Serial.println(dataPoints[index]);
	
	index = updateValue(index, up, 0, 100, !cycles);
}

void VarianceTester::computeVariance()
{
	// compute average
	double avgSum = 0;
	for (int n=0;n<100;n++)
	{
		avgSum += dataPoints[n];
	}
	avg = avgSum/100;
	
	// compute variance
	double sum = 0;
	
	Serial.print("starting sum is equal to: ");
	Serial.println(sum);
	
	for (int n=0;n<100;n++)
	{
		double diff = dataPoints[n] - avg;
		
		double diffSquared = diff*diff;
		
		Serial.print(diff);Serial.print(" ~~ ");
		
		sum += diffSquared;
		
		
		Serial.print(n);Serial.print(" // ");
		Serial.print(diff); Serial.print(" -- ");
		Serial.println(sum);
		
	}
	variance = sum/100;
	
	Serial.print("band: ");
	Serial.print(band);
	Serial.print(" variance: ");
	Serial.print((int)variance);
	Serial.print(" average: ");
	Serial.print((int)avg);
	Serial.print(" varSum: ");
	Serial.println(sum);
	
	
	delay(1000);
}

void VarianceTester::resetValues()
{
	variance = 0;
	index = 0;
	avg = 0;
	
	for (int n=0;n<100;n++)
	{
		dataPoints[n] = 0;
	}
	
	band = updateValue(band, up, 0, 6, cycles);
}











































