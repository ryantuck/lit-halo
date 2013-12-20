//	########################################################################

//  InProgressCustomFoos.cpp

//	8/23/13

//	########################################################################

#include "InProgressCustomFoos.h"








TestingFoo::TestingFoo()
{
	MovingFoo* aFoo = new MovingFoo();
	
	Step<MovingFoo>* mStep = new Step<MovingFoo>;
	mStep->fnPtr = &MovingFoo::move;
	mStep->period = 5;
	aFoo->addStep(mStep);
	
	aFoo->addLEDs(LITColor.magenta, maxBrightness, 5, 5);
	addFoo(aFoo);
	
	counter = 0;
	
	Step<TestingFoo>* aStep = new Step<TestingFoo>;
	aStep->period = 5;
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


EverythingTester::EverythingTester()
{
	numSamples	= 100;
	sampleCount = 0;
	
	potIndex	= 0;
	brIndex		= 0;
	numIndex	= 0;
	
	for (int n=0;n<7;n++)
	{
		spectrumData[n] = 0;
	}
	
	for (int n=0;n<7;n++)
	{
		stats[n] = new Stats(110);
	}
	
	Step<EverythingTester>* collect = new Step<EverythingTester>;
	collect->fnPtr = &EverythingTester::collectData;
	collect->count = numSamples;
	addStep(collect);
	
	Step<EverythingTester>* display = new Step<EverythingTester>;
	display->fnPtr = &EverythingTester::displayData;
	display->count = 1;
	addStep(display);
	
	Step<EverythingTester>* updParams = new Step<EverythingTester>;
	updParams->fnPtr = &EverythingTester::updateParameters;
	updParams->count = 1;
	addStep(updParams);
	
	Step<EverythingTester>* change = new Step<EverythingTester>;
	change->fnPtr = &EverythingTester::changeFoos;
	change->count = 1;
	addStep(change);
	
}

void EverythingTester::collectData()
{
	// sample 100 times
	sampleCount++;
	
	for (int n=0;n<7;n++)
	{
		int x = spectrumData[n];
		x += (audio.eq.spectrum[n] - x)/sampleCount;
		spectrumData[n] = x;
		
		stats[n]->update(audio.eq.spectrum[n]);
	}
}

void EverythingTester::displayData()
{
	// print out data
	Serial.print(8*potIndex+1);		Serial.print(",");
	Serial.print(25*brIndex);	Serial.print(",");
	Serial.print(8*numIndex);	Serial.print(",");
	
	for (int n=0;n<7;n++)
	{
		Serial.print(spectrumData[n]);
		Serial.print(",");
	}
	
	for (int n=0;n<7;n++)
	{
		stats[n]->getStats();
		Serial.print(stats[n]->stdev);
		Serial.print(",");
	}
	Serial.println();
	
	// delay
	delay(500);
}

void EverythingTester::updateParameters()
{
	// change pot, num, brightness if necessary
	
	potIndex = updateValue(potIndex, up, 0, 15, cycles);
	
	if (potIndex == 0)
	{
		numIndex = updateValue(numIndex, up, 0, 4, cycles);
		
		if (numIndex == 0)
		{
			brIndex	 = updateValue(brIndex, up, 0, 4, cycles);
		}
	}
	
	for (int n=0;n<7;n++)
	{
		spectrumData[n] = 0;
		stats[n]->clear();
	}
	sampleCount = 0;
}

void EverythingTester::changeFoos()
{
	audio.pot.update(8*potIndex+1);
	
	fLEDs.removeAllEntries();
	
	// 0 - none
	// 1 - 8 - every 4
	// 2 - 16 - every 2
	// 3 - 24 - 3 on, 1 off
	// 4 - 32 - all on
	
	if (numIndex > 0)
	{
		for (int n=0;n<8;n++)
		{
			addLEDs(LITColor.white, 25*brIndex, 4*n, 4*n + numIndex - 1);
		}
	}
	
}

BeatCollector::BeatCollector()
{
	sampleCount = 0;
	lightCounter = 0;
	dataPoints = 100;
	
	for (int n=0;n<7;n++)
	{
		for (int m=0;m<dataPoints;m++)
		{
			specData[n][m] = 0;
		}
	}
	
	addLEDs(LITColor.red, maxBrightness, 0, 0);
	
	Serial.println("constructor works!");
	
	Step<BeatCollector>* step0 = new Step<BeatCollector>;
	step0->fnPtr = &BeatCollector::stopLight;
	step0->count = 3;
	addStep(step0);
	
	Step<BeatCollector>* stepA = new Step<BeatCollector>;
	stepA->fnPtr = &BeatCollector::collectData;
	stepA->count = dataPoints;
	addStep(stepA);
	
	Step<BeatCollector>* stepB = new Step<BeatCollector>;
	stepB->fnPtr = &BeatCollector::printData;
	stepB->count = 1;
	addStep(stepB);
}

void BeatCollector::stopLight()
{
	fLEDs.entry(0)->me->color.setColor(*LITColor.colorList[lightCounter]);
	delay(1000);
	lightCounter++;
	
	if (lightCounter == 3)
	{
		fLEDs.entry(0)->me->brightness = 0;
	}
	
}

void BeatCollector::collectData()
{
	for (int n=0;n<7;n++)
	{
		int tmp = audio.eq.spectrum[n]/8;
		specData[n][sampleCount] = (byte) tmp;
	}
	
	sampleCount++;
}

void BeatCollector::printData()
{
	for (int m=0;m<dataPoints;m++)
	{
		for (int n=0;n<7;n++)
		{
			Serial.print(specData[n][m]);
			Serial.print(",");
		}
		Serial.println();
	}
	
	Serial.println();
	Serial.println();
	Serial.println();
	
	delay(5000);
	
	sampleCount = 0;
	lightCounter = 0;
	fLEDs.entry(0)->me->brightness = maxBrightness;
}


FullSongListener::FullSongListener()
{
	Step<FullSongListener>* collect = new Step<FullSongListener>;
	collect->fnPtr = &FullSongListener::collectData;
	addStep(collect);
	
	Serial.println("==========================");
}

void FullSongListener::collectData()
{
	for (int n=0;n<7;n++)
	{
		Serial.print(audio.eq.spectrum[n]);
		Serial.print(",");
	}
	Serial.println();
}



RedGreenMover::RedGreenMover()
{
	for (int n=0;n<8;n++)
	{
		addLEDs(LITColor.red, maxBrightness, 4*n, 4*n);
//		addLEDs(LITColor.green, maxBrightness, 4*n+1, 4*n+1);
		addLEDs(LITColor.green, maxBrightness, 4*n+2, 4*n+2);
	}
	
	Step<MovingFoo>* m = new Step<MovingFoo>;
	m->fnPtr = &MovingFoo::move;
	m->period = 3;
	addStep(m);
}

RedGreenPulser::RedGreenPulser()
{
	for (int n=0;n<16;n++)
	{
		addLEDs(LITColor.red, 0, 2*n,2*n);
	}
	
	for (int n=0;n<16;n++)
	{
		addLEDs(LITColor.green, maxBrightness, 2*n+1, 2*n+1);
	}
	
	pulseCounter = 0;
	
	Step<RedGreenPulser>* r = new Step<RedGreenPulser>;
	r->fnPtr = &RedGreenPulser::redUpGreenDown;
	r->count = 50;
	addStep(r);
	
	Step<RedGreenPulser>* g = new Step<RedGreenPulser>;
	g->fnPtr = &RedGreenPulser::redDownGreenUp;
	g->count = 50;
	addStep(g);
}

void RedGreenPulser::redUpGreenDown()
{
	for (int r=0;r<16;r++)
	{
		fLEDs.entry(r)->me->brightness += 2;
	}
	
	for (int g=16;g<32;g++)
	{
		fLEDs.entry(g)->me->brightness -= 2;
	}
}

void RedGreenPulser::redDownGreenUp()
{
	for (int r=0;r<16;r++)
	{
		fLEDs.entry(r)->me->brightness -= 2;
	}
	
	for (int g=16;g<32;g++)
	{
		fLEDs.entry(g)->me->brightness += 2;
	}
}



RedGreenAlternater::RedGreenAlternater()
{
	for (int n=0;n<4;n++)
	{
		addLEDs(LITColor.red, maxBrightness, 8*n, 8*n);
	}
	
	for (int n=0;n<4;n++)
	{
		addLEDs(LITColor.green, 0, 8*n+1, 8*n+1);
	}
	
	add1 = 0;
	add2 = 1;
	
	Step<RedGreenAlternater>* a = new Step<RedGreenAlternater>;
	a->fnPtr = &RedGreenAlternater::aUp;
	a->count = 20;
	addStep(a);
	
	Step<RedGreenAlternater>* x = new Step<RedGreenAlternater>;
	x->fnPtr = &RedGreenAlternater::add1Up;
	x->count = 1;
	addStep(x);
	
	Step<RedGreenAlternater>* b = new Step<RedGreenAlternater>;
	b->fnPtr = &RedGreenAlternater::bUp;
	b->count = 20;
	addStep(b);
	
	Step<RedGreenAlternater>* y = new Step<RedGreenAlternater>;
	y->fnPtr = &RedGreenAlternater::add2Up;
	y->count = 1;
	addStep(y);
}

void RedGreenAlternater::aUp()
{
	for (int r=0;r<4;r++)
	{
		fLEDs.entry(r)->me->brightness -= 5;
	}
	
	for (int g=4;g<8;g++)
	{
		fLEDs.entry(g)->me->brightness += 5;
	}
	
	Serial.println("aUp");
	Serial.print("r: ");
	Serial.println(fLEDs.entry(0)->me->brightness);
	Serial.print("g: ");
	Serial.println(fLEDs.entry(4)->me->brightness);
}

void RedGreenAlternater::bUp()
{
	for (int r=0;r<4;r++)
	{
		fLEDs.entry(r)->me->brightness += 5;
	}
	
	for (int g=4;g<8;g++)
	{
		fLEDs.entry(g)->me->brightness -= 5;
	}
}

void RedGreenAlternater::add1Up()
{
	add1 = updateValue(add1, up, 0, 7, cycles);
	add1 = updateValue(add1, up, 0, 7, cycles);
	
	for (int n=0;n<4;n++)
	{
		fLEDs.entry(n)->me->address = 8*n + add1;
	}
}

void RedGreenAlternater::add2Up()
{
	add2 = updateValue(add2, up, 0, 7, cycles);
	add2 = updateValue(add2, up, 0, 7, cycles);
	
	for (int n=0;n<4;n++)
	{
		fLEDs.entry(4+n)->me->address = 8*n + add2;
	}
}

ChristmasSnakes::ChristmasSnakes()
{
	Step<ChristmasSnakes>* aStep = new Step<ChristmasSnakes>;
	aStep->fnPtr = &ChristmasSnakes::checkForNoSnakes;
	addStep(aStep);
	
	baseCycler = 0;
}

void ChristmasSnakes::checkForNoSnakes()
{
	if (!hasFoos())
	{
		EphemeralSnake* aSnake = new EphemeralSnake(0,16,1,&LITColor.red);
		addFoo(aSnake);
		
		EphemeralSnake* bSnake = new EphemeralSnake(16,16,1,&LITColor.green);
		addFoo(bSnake);
	}
}

ChristmasSparkler::ChristmasSparkler()
{
	rgw[0].setColor(LITColor.red);
	rgw[1].setColor(LITColor.green);
	rgw[2].setColor(LITColor.white);
	
	totalSparkles = 12;
	colorCount = 0;
	
	Step<ChristmasSparkler>* n = new Step<ChristmasSparkler>;
	n->fnPtr = &ChristmasSparkler::newSparkle;
	n->count = 1;
	addStep(n);
	
	Step<ChristmasSparkler>* s = new Step<ChristmasSparkler>;
	s->fnPtr = &ChristmasSparkler::stall;
	s->count = 10;
	addStep(s);
}

void ChristmasSparkler::newSparkle()
{
	int addr = rand()%32;
	
	while (!checkAddresses(addr))
	{
		addr = rand()%32;
	}
	
	InAndOutFader* x = new InAndOutFader(rgw[colorCount],addr);
	addFoo(x);
	
	colorCount = updateValue(colorCount, up, 0, 2, cycles);
}

void ChristmasSparkler::stall()
{
	// wait to create a new one
}

bool ChristmasSparkler::checkAddresses(int x)
{
	bool check = true;
	
	for (int n=0;n<countFoos();n++)
	{
		int z = foos.entry(n)->me->fLEDs.entry(0)->me->address;
		
		if (z == x)
		{
			check = false;
		}
	}
	
	return check;
}


InAndOutFader::InAndOutFader(Color aColor,int addr)
{
	repeats = false;
	
	addLEDs(aColor, 0, addr, addr);
	
	totalIterations = 0;
	
	Step<InAndOutFader>* a = new Step<InAndOutFader>;
	a->fnPtr = &InAndOutFader::fade;
	a->count = 100;
	addStep(a);
	
	
	
}

void InAndOutFader::getBrighter()
{
	int x = fLEDs.entry(0)->me->brightness;
	x = updateValue(x, up, 0, 100, !cycles);
	fLEDs.entry(0)->me->brightness = x;
	
}

void InAndOutFader::dimDown()
{
	int x = fLEDs.entry(0)->me->brightness;
	x--;
	fLEDs.entry(0)->me->brightness = x;
}

void InAndOutFader::fade()
{
	int x = fLEDs.entry(0)->me->brightness;
	
	if (totalIterations < 50)
	{
		x = updateValue(x, up, 0, 100, !cycles);
		x = updateValue(x, up, 0, 100, !cycles);
	}
	else
	{
		x = updateValue(x, down, 0, 100, !cycles);
		x = updateValue(x, down, 0, 100, !cycles);
	}

	fLEDs.entry(0)->me->brightness = x;
	
	totalIterations++;
}



JoshFoo::JoshFoo()
{
	// create 16 LEDs
	for (int n=0;n<16;n++)
	{
		int addr = 2*n;
		
		addLEDs(LITColor.white, maxBrightness, addr,addr);
	}
	
	colorIndex = 0;
	
	Step<MovingFoo>* m = new Step<MovingFoo>;
	m->fnPtr = &MovingFoo::move;
	m->period = 4;
	m->count = 10;
	addStep(m);
	
	Step<JoshFoo>* cc = new Step<JoshFoo>;
	cc->fnPtr = &JoshFoo::changeColor;
	cc->count = 1;
	addStep(cc);
}

void JoshFoo::changeColor()
{
	for (int n=0;n<16;n++)
	{
		fLEDs.entry(n)->me->color.setColor(*LITColor.colorList[colorIndex]);
	}
	
	colorIndex = updateValue(colorIndex, up, 0, 5, cycles);
}


TwoMovers::TwoMovers()
{
	MovingDot* a = new MovingDot(LITColor.red,0,5);
	MovingDot* b = new MovingDot(LITColor.yellow,1,16);
	
	addFoo(a);
	addFoo(b);
}



RainbowShooter::RainbowShooter()
{
	Step<RainbowShooter>* a = new Step<RainbowShooter>;
	a->fnPtr = &RainbowShooter::addNewDot;
	a->period = 16;
	addStep(a);
}

void RainbowShooter::addNewDot()
{
	MovingDot* x = new MovingDot(*LITColor.colorList[colorCount],1,0);
	x->repeats = false;
	x->steps.entry(0)->me->count = 31;
	addFoo(x);
	
	colorCount = updateValue(colorCount, up, 0, 5, cycles);
}


SwitchingDR::SwitchingDR()
{
	DoubleRainbow* dr = new DoubleRainbow();
	addFoo(dr);
}

void SwitchingDR::checkers()
{
	if (audio.beatJustDetected(1))
	{
		
	}
}




















































