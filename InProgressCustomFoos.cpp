//	########################################################################

//  InProgressCustomFoos.cpp

//	8/23/13

//	########################################################################

#include "InProgressCustomFoos.h"



ListenerWithBunch::ListenerWithBunch()
{
	addStepWithFunction(&ListenerWithBunch::listenUp, 1);
}

void ListenerWithBunch::listenUp()
{
	if (audio.beats.detected())
	{
		FiniteBunch* fb = new FiniteBunch;
		addFoo(fb);
	}
}

// ========================================================================

FiniteBunch::FiniteBunch()
{
	for (int n=0;n<8;n++)
	{
		addLEDs(LITColor.white, maxBrightness, 4*n, 4*n);
	}
	
	layer = 2;
	
	repeats = false;
	
	addStepWithFunction(&MovingFoo::move, 1, 32);
}

// ========================================================================

SlowMovingDot::SlowMovingDot()
{
	back	= 0;
	middle	= 1;
	lead	= 2;
	
	addLEDs(LITColor.red, maxBrightness, back, back);
	addLEDs(LITColor.red, maxBrightness, middle, middle);
	addLEDs(LITColor.red, 0, lead, lead);
	
	addStepWithFunction(&SlowMovingDot::changeEdges, 10, 20);
	addStepWithFunction(&SlowMovingDot::changeEntries, 1, 1);
}

void SlowMovingDot::changeEdges()
{
	fLEDs.entry(back)->me->brightness -= 5;
	fLEDs.entry(lead)->me->brightness += 5;
}

void SlowMovingDot::changeEntries()
{
	changeAddresses();
	
	int tmpBack = back;
	
	back = middle;
	middle = lead;
	lead = tmpBack;
}

void SlowMovingDot::changeAddresses()
{
	int x = fLEDs.entry(back)->me->address;
	x = updateValue(x, up, 0, 31, cycles);
	x = updateValue(x, up, 0, 31, cycles);
	x = updateValue(x, up, 0, 31, cycles);
	fLEDs.entry(back)->me->address = x;
}

// ========================================================================

BrightnessTest::BrightnessTest()
{
	addLEDs(LITColor.red, 5, 28,28);
	addLEDs(LITColor.red, 10, 26, 26);
	addLEDs(LITColor.red, 20, 24, 24);
	addLEDs(LITColor.red, 50, 22, 22);
	addLEDs(LITColor.red, 100, 20, 20);
	
	addLEDs(LITColor.red, 3, 8, 8);
	addLEDs(LITColor.red, maxBrightness, 9, 9);
	addLEDs(LITColor.red, 3, 10, 10);
}

// ========================================================================

SuperSlowDot::SuperSlowDot()
{
	addLEDs(LITColor.red, 10, 0, 0);
	addLEDs(LITColor.red, 0, 1, 1);
	
	trailIndex = 0;
	leadIndex = 1;
	
	brIndex = 0;
	
	addStepWithFunction(&SuperSlowDot::changeBrightness, 1, 100);
	addStepWithFunction(&SuperSlowDot::moveBack, 1, 1);
}

void SuperSlowDot::changeBrightness()
{
	brIndex++;
	
	if (brIndex % 10 == 0)
	{
		LED* trailer = fLEDs.entry(trailIndex)->me;
		LED* leader = fLEDs.entry(leadIndex)->me;
		trailer->brightness --;
		leader->brightness ++;
	}
}

void SuperSlowDot::moveBack()
{
	AddressedLED* trailer = fLEDs.entry(trailIndex)->me;
	
	trailer->address = updateValue(trailer->address, up, 0, 31, cycles);
	trailer->address = updateValue(trailer->address, up, 0, 31, cycles);
	
	trailIndex = updateValue(trailIndex, up, 0, 1, cycles);
	leadIndex = updateValue(leadIndex, up, 0, 1, cycles);
	
	brIndex = 0;
}

// ========================================================================

ASlowDot::ASlowDot()
{
	MovingDot* x = new MovingDot(LITColor.green,up,0);
	addFoo(x);
	
	x->steps.entry(0)->me->period = 4;
}

// ========================================================================

ZeroColorSwitcher::ZeroColorSwitcher()
{
	MovingFoo* x = new MovingFoo;
	x->direction = up;
	addFoo(x);
	thisGuy = x;
	
	thisGuy->addLEDs(LITColor.red, maxBrightness, 20, 27);
	
	headLED = thisGuy->fLEDs.entry(thisGuy->countLEDs()-1)->me;
	tailLED = thisGuy->fLEDs.entry(0)->me;
	
	colorIndex = 0;
	
	
	thisGuy->addStepWithFunction(&MovingFoo::move, 4,1);
	addStepWithFunction(&ZeroColorSwitcher::checkForColorTriggers, 1,1);
	
}

void ZeroColorSwitcher::checkForColorTriggers()
{
	// determine whether currently passing through
	if (thisGuy->direction)
	{
		if (headLED->address == 0)
		{
			isPassing = true;
		}
		if (tailLED->address == 1)
		{
			isPassing = false;
			colorIndex = updateValue(colorIndex, up, 0, 5, cycles);
		}
	}
	
	if (thisGuy->direction)
	{
		for (int n=0;n<thisGuy->countLEDs();n++)
		{
			AddressedLED* x = thisGuy->fLEDs.entry(n)->me;
			
			if (x->address == 0)
			{
				// switch color
				x->color.setColor(*LITColor.colorList[colorIndex]);
			}
		}
	}
	else
	{
		for (int n=0;n<countLEDs();n++)
		{
			AddressedLED* x = fLEDs.entry(n)->me;
			
			if (x->address == 31)
			{
				// switch color
			}
		}
	}
}

// ========================================================================

TenDotFaders::TenDotFaders()
{
	addStepWithFunction(&TenDotFaders::checkForFoos, 1);
}

void TenDotFaders::checkForFoos()
{
	if (!hasFoos())
	{
		addTen();
	}
}

void TenDotFaders::addTen()
{
	int usedAddresses[12];
	for (int n=0;n<12;n++)
	{
		usedAddresses[n] = 0;
	}
	
	for (int n=0;n<12;n++)
	{
		int cIndex = n % 6;
		
		bool addrOk = false;
		
		int addr = rand() % 32;
		
		while (!addrOk)
		{
			addr = rand() % 32;
			addrOk = true;
			
			for (int a=0;a<n;a++)
			{
				if (addr == usedAddresses[a])
				{
					addrOk = false;
				}
			}
			
			if (addrOk)
			{
				usedAddresses[n] = addr;
			}
		}
		
		InAndOutFader* x = new InAndOutFader(*LITColor.colorList[cIndex],
											 addr);
		addFoo(x);
	}
}

// ========================================================================

MovingFadingDot::MovingFadingDot()
{
	MovingDot* x = new MovingDot(LITColor.green,up,0);
	addFoo(x);
	
	theLED = x->fLEDs.entry(0)->me;
	
	repeats = false;
	
	addStepWithFunction(&MovingFadingDot::reduceBrightness, 1, 100);
}

void MovingFadingDot::reduceBrightness()
{
	theLED->brightness = updateValue(theLED->brightness,
									 down,
									 0,
									 100,
									 !cycles);
}

// ========================================================================

LotsOfMovingFadingDots::LotsOfMovingFadingDots()
{
	maxFoos = 12;
	
	// looks pretty cool setting period to 5
	addStepWithFunction(&LotsOfMovingFadingDots::checkFoos, 12);
}

void LotsOfMovingFadingDots::checkFoos()
{
	if (countFoos() < maxFoos)
	{
		MovingFadingDot* x = new MovingFadingDot();
		addFoo(x);
	}
}

// ========================================================================

FadinDubbyBowz::FadinDubbyBowz()
{
	addStepWithFunction(&FadinDubbyBowz::checkMyShit, 1);
	
	addFoo(new DoubleRainbow);
	
	dr = foos.entry(0)->me;
	
	r1 = dr->foos.entry(0)->me;
	r2 = dr->foos.entry(1)->me;
}


void FadinDubbyBowz::checkMyShit()
{
    if (audio.beats.detected())
	{
		// set brightness of DR to max brightness
		for (int n=0;n<r1->countLEDs();n++)
		{
			r1->fLEDs.entry(n)->me->brightness = maxBrightness;
			r2->fLEDs.entry(n)->me->brightness = maxBrightness;
		}
	}
	else
	{
		// reduce brightness
		for (int n=0;n<r1->countLEDs();n++)
		{
			r1->fLEDs.entry(n)->me->brightness *= 0.5;
			r2->fLEDs.entry(n)->me->brightness *= 0.5;
		}
	}
	
	MovingFoo* x = (MovingFoo*)r1;
	MovingFoo* y = (MovingFoo*)r2;
	
	x->move();
	y->move();
}

PairHolder::PairHolder()
{
	DotPair* x1 = new DotPair(0,6,up);
	DotPair* x2 = new DotPair(0,6,down);
	//DotPair* x3 = new DotPair(0,5,up);
	addFoo(x1);
	addFoo(x2);
	
}


SpeedChangerDot::SpeedChangerDot(Color aColor, int start, bool increasing, int longest, bool aDirection)
{
	repeats = false;
	
	int total = 0;
	for (int n=0;n<longest;n++)
	{
		int iter = (n+1)*(longest-n);
		total += iter;
	}
	
	addLEDs(aColor, maxBrightness, start, start);
	addStepWithFunction(&SpeedChangerDot::iterate, 1, total);
	isIncreasing = increasing;
	
	direction	= aDirection;
	pCounter	= 0;
	mCounter	= 0;
	
	if (isIncreasing)
	{
		per	= 1;
		mov	= longest;
	}
	else
	{
		per	= longest;
		mov	= 1;
	}
}

void SpeedChangerDot::iterate()
{
	pCounter++;
	
	if (pCounter == per)
	{
		move();
		
		pCounter = 0;
		mCounter++;
		
		if (mCounter == mov)
		{
			if (isIncreasing)
			{
				per++;
				mov--;
			}
			else
			{
				per--;
				mov++;
			}
			
			mCounter = 0;
		}
	}
}

DotPair::DotPair(int start, int longest, bool aDirection)
{
	startAtZero = start;
	addStepWithFunction(&DotPair::checkForFoos, 1);
	index			= 1;
	per				= longest;
	startAddress	= start;
	startOffset		= 1;
	direction		= aDirection;
	
	
	for (int n=0;n<longest;n++)
	{
		startOffset += n+1;
	}
}

void DotPair::checkForFoos()
{
	if (!hasFoos())
	{
		index		= updateValueBy(index, up, 2, 0, 5, cycles);
		int index2	= updateValueBy(index, up, 3, 0, 5, cycles);
		
		startAddress = updateValueBy(startAddress, direction, startOffset, 0, 31, cycles);
		
		SpeedChangerDot* a = new SpeedChangerDot(*LITColor.colorList[index],startAddress,true,per,direction);
		SpeedChangerDot* b = new SpeedChangerDot(*LITColor.colorList[index2],startAddress,false,per,direction);

		addFoo(a);
		addFoo(b);
	}
}

WhiteBrightnessTest::WhiteBrightnessTest()
{
	// empirical test to determine how brightness can be adjusted
	// to make combination colors (white, yellow, cyan, etc) match
	// single colors (red,green,blue).
	
	addLEDs(LITColor.yellow, 50, 9, 9);
	addLEDs(LITColor.green, maxBrightness, 10, 10);
	addLEDs(LITColor.white, 25, 11, 11);
	
	addLEDs(LITColor.yellow, maxBrightness, 15, 15);
	addLEDs(LITColor.green, maxBrightness, 16, 16);
	addLEDs(LITColor.white, maxBrightness, 17, 17);
	
	// i think this relationship works the best
	addLEDs(LITColor.yellow, 67, 20, 20);
	addLEDs(LITColor.green, maxBrightness, 21, 21);
	addLEDs(LITColor.white, 33, 22, 22);
}

BackgroundCycler::BackgroundCycler()
{
	cycler = 0;
	
	addStepWithFunction(&BackgroundCycler::checkForBeat, 1);
}

void BackgroundCycler::checkForBeat()
{
	if (audio.beats.detected())
	{
		foos.removeAllEntries();
		
		switch (cycler)
		{
			case 0:
			{
				RainbowFountain* a = new RainbowFountain(up);
				addFoo(a);
				break;
			}
			case 1:
			{
				RainbowPulser* b = new RainbowPulser;
				addFoo(b);
				break;
			}
			case 2:
			{
				EvenEphemSnakes* c = new EvenEphemSnakes;
				addFoo(c);
				break;
			}
			case 3:
			{
				TwoColorParticleJam* d = new TwoColorParticleJam(LITColor.green,LITColor.blue);
				addFoo(d);
				break;
			}
		}
		
		cycler = updateValue(cycler, up, 0, 3, cycles);
	}
}

// ========================================================================

FadinDubbyBowz2::FadinDubbyBowz2()
{
	addStepWithFunction(&FadinDubbyBowz2::checkMyShit, 1);
	
    
	addFoo(new DoubleRainbow);
    addFoo(new StillEvenlySpaced(maxBrightness, LITColor.yellow, 16, 0));
    //addFoo(new Sparkle);
   
    
	
	dr = foos.entry(0)->me;
	
	r1 = dr->foos.entry(0)->me;
	r2 = dr->foos.entry(1)->me;
           
    es = foos.entry(1)->me;
    
    Serial.println(es->countLEDs());
}

void FadinDubbyBowz2::checkMyShit()
{
    if (audio.beats.detected())
	{
		// set brightness of DR to max brightness
        Serial.println(r2->countLEDs());
		for (int n=0;n<r1->countLEDs();n++)
		{
			r1->fLEDs.entry(n)->me->brightness = maxBrightness;
			r2->fLEDs.entry(n)->me->brightness = maxBrightness;
		}
	}
	else
	{
		// reduce brightness
		for (int n=0;n<r1->countLEDs();n++)
		{
			r1->fLEDs.entry(n)->me->brightness *= 0.5;
			r2->fLEDs.entry(n)->me->brightness *= 0.5;
		}
	}
    
    if (audio.beats2.detected())
    //if(false)
	{
		// set brightness of ES to max brightness
		for (int n=0;n<es->countLEDs();n++)
		{
			es->fLEDs.entry(n)->me->brightness = maxBrightness;
           
		}
	}
	else
	{
		// reduce brightness
		for (int n=0;n<es->countLEDs();n++)
		{
			es->fLEDs.entry(n)->me->brightness *= .5;
		}
	}
}

FountainHead::FountainHead()
{
    Foo* a = new Foo;
    Foo* b = new Foo;
    Foo* c = new Sparkle2;
    a->addLEDs(LITColor.magenta, maxBrightness, 0, 15);
    b->addLEDs(LITColor.yellow, maxBrightness, 16, 31);
    
    addFoo(a);
    addFoo(b);
    addFoo(c);
    
    lineLength = 10;
    addStepWithFunction(&FountainHead::checkMyShit, 1);
    
}

void FountainHead::checkMyShit()
{
    
    Serial.println(lineLength);
    if(audio.beats.detected())
    {
        lineLength = 16;
    }
    else
    {
        if(lineLength <= 1) lineLength = 0;
        else lineLength--;
    }
    
    for(int n=0; n< 16; n++)
    {
        foos.entry(0)->me->fLEDs.entry(n)->me->color = LITColor.black;
        foos.entry(1)->me->fLEDs.entry(n)->me->color = LITColor.black;
    }
    for(int n=0; n < lineLength; n++)
    {
        foos.entry(0)->me->fLEDs.entry(n)->me->color = LITColor.magenta;
        foos.entry(1)->me->fLEDs.entry(15-n)->me->color = LITColor.yellow;
    }

}

Fireworks::Fireworks(Color aColor)
{
	numberOfLEDs		= 1;
	isIncreasing		= true;
	maxLEDs				= 8;
    
    myColor = aColor;

	addStepWithFunction(&Fireworks::flashLEDs, 2, 2);
	addStepWithFunction(&Fireworks::changeNumberOfLEDs, 1, 1);
}

void Fireworks::flashLEDs()
{
	fLEDs.removeAllEntries();
	
	for (int n=0;n<numberOfLEDs;n++)
	{
		int addr = rand()%32;
		addLEDs(myColor, maxBrightness, addr, addr);
	}
}

void Fireworks::changeNumberOfLEDs()
{
	if (isIncreasing)
	{
		numberOfLEDs = numberOfLEDs + 2;
	}
	else
	{
		numberOfLEDs = numberOfLEDs - 2;
	}
	
	if (numberOfLEDs >- maxLEDs)
	{
		isIncreasing = false;
	}
	
	if (numberOfLEDs <= 0)
	{
		repeats = false;
	}
}

FireworksHolder::FireworksHolder()
{
    
    state = 1;
    addFoo(new Fireworks(LITColor.green));
    addStepWithFunction(&FireworksHolder::checkMyShit, 1);
}

void FireworksHolder::checkMyShit()
{
	if (audio.bassBeatDetected && foos.length() < 4)
    {
        if(state)
        {
            addFoo(new Fireworks(LITColor.green));
            state = 0;
        }
        else
        {
            addFoo(new Fireworks(LITColor.white));
            state = 1;
        }

    }
}


// ========================================================================
BeatMania::BeatMania()
{
    addStepWithFunction(&BeatMania::checkMyShit, 1);
    addStepWithFunction(&BeatMania::clear, 2);
}

void BeatMania::checkMyShit()
{
    if (audio.bassBeatDetected)
    {
        foos.removeAllEntries();
        int index = rand()%7;
        
        switch (index)
        {
            case 0:
                addFoo(new StillRainbow(50));
                break;
            case 1:
                addFoo(new StillDoubleRainbow(50));
                break;
            case 2:
                addFoo(new AllOn(LITColor.white,50));
                break;
            case 3:
                addFoo(new AllOn(LITColor.green,50));
                break;
            case 4:
                addFoo(new AllOn(LITColor.yellow,50));
                break;
            case 5:
                addFoo(new StillEvenlySpaced(50,LITColor.magenta,4,0));
                break;
            case 6:
                addFoo(new StillEvenlySpaced(50,LITColor.cyan,16,0));
                break;
            case 7:
                addFoo(new StillDubz(50));
                break;
        }
    }
}

void BeatMania::clear()
{
    foos.removeAllEntries();
}



// ========================================================================




// ========================================================================

CloseColorDots::CloseColorDots(int number)
{
	colorIndex = 0;
	maxColorIndex = 20;
	
	for (int n=0;n<number;n++)
	{
		Color myColor;
		myColor.calculateRGB(maxColorIndex, n);
		
		MovingDot* x = new MovingDot(myColor,rand()%2,rand()%32);
		x->steps.entry(0)->me->period = rand()%4+2;
		addFoo(x);
	}
	
	addStepWithFunction(&CloseColorDots::cycleThroughColors, 8);
}

void CloseColorDots::cycleThroughColors()
{
	colorIndex = updateValue(colorIndex, up, 0, maxColorIndex, cycles);
	
	for (int n=0;n<countFoos();n++)
	{
		int tmpIndex = updateValueBy(colorIndex, up, n, 0, maxColorIndex, cycles);
		
		foos.entry(n)->me->fLEDs.entry(0)->me->color.calculateRGB(maxColorIndex, tmpIndex);
	}
}



// ========================================================================

Explosion::Explosion()
{
	addStepWithFunction(&Explosion::moveAndFade, 1,1);
	
	for (int n=0;n<6;n++)
	{
		MovingDot* x = new MovingDot(*LITColor.colorList[n],n%2,0);
		x->steps.entry(0)->me->period = n+1;
		addFoo(x);
	}
}


void Explosion::moveAndFade()
{
	for (int n=0;n<countFoos();n++)
	{
		foos.entry(n)->me->fLEDs.entry(0)->me->brightness *= 0.95;
		
		if (foos.entry(n)->me->fLEDs.entry(0)->me->brightness == 0)
		{
			repeats = false;
		}
	}
}

ExplosionHolder::ExplosionHolder()
{
	addStepWithFunction(&ExplosionHolder::listen, 1);
}

void ExplosionHolder::listen()
{
	if (audio.beats.detected())
	{
		addFoo(new Explosion());
	}
}


// ========================================================================

FanOut::FanOut()
{
	for (int n=0;n<8;n++)
	{
		addFoo(new MovingDot(*LITColor.colorList[n/2],n%2, 15+n%2));
		foos.entry(n)->me->steps.entry(0)->me->period = pow(2,n/2);
	}
	
	addStepWithFunction(&FanOut::fan, 16);
}

void FanOut::fan()
{
	for (int n=0;n<countFoos();n++)
	{
		MovingDot* x = (MovingDot*)foos.entry(n)->me;
		x->switchDirection();
	}
}


BeatMotionStopper::BeatMotionStopper()
{
	motionOn	= true;
	maxCount	= 15;
	mCount		= 0;
	
	addStepWithFunction(&BeatMotionStopper::checkForBeats, 1);
	
	addLEDs(LITColor.orange, maxBrightness, 0, 10);
}

void BeatMotionStopper::checkForBeats()
{
	updateMotionCount();
	
	if (audio.beats.detected())
	{
		motionOn = false;
	}
	
	if (motionOn)
	{
		move(0);
	}
}

void BeatMotionStopper::updateMotionCount()
{
	if (!motionOn)
	{
		mCount++;
		
		if (mCount == maxCount)
		{
			mCount = 0;
			motionOn = true;
		}
	}
}

AppearAndFadeEvent::AppearAndFadeEvent()
{
	addStepWithFunction(&AppearAndFadeEvent::checkForBeats, 1);
}

void AppearAndFadeEvent::checkForBeats()
{
	if (audio.beats.detected())
	{
		if (hasLEDs())
		{
			fLEDs.removeAllEntries();
		}
		
		// create 10 random LEDs
		for (int n=0;n<20;n++)
		{
			int addr = rand()%32;
			addLEDs(*LITColor.spectrum[rand()%12], maxBrightness, addr, addr);
		}
	}
	
	for (int n=0;n<countLEDs();n++)
	{
		fLEDs.entry(n)->me->brightness *= 0.9;
	}
}

SpringDot::SpringDot(Color aColor, int start, bool aDirection)
{
	addFoo(new MovingDot(aColor,aDirection,start));
	dot = (MovingDot*)foos.entry(0)->me;
	
	addStepWithFunction(&SpringDot::adjust, 1);
}

void SpringDot::adjust()
{
	changePeriod();
	checkDirection();
}

void SpringDot::changePeriod()
{
	int currentAddress = dot->fLEDs.entry(0)->me->address;
	dot->steps.entry(0)->me->period = newPeriod(currentAddress);
}

int SpringDot::newPeriod(int addr)
{
	// period = C / (256-x^2)^(1/2)
	
	int newPeriod = 1;
	
	int d = 0;
	
	if (addr < 16)
	{
		int distance = addr - 15;
		d = abs(distance);
	}
	else
	{
		int distance = addr - 16;
		d = abs(distance);
	}
	
	newPeriod = 28 / (pow(256 - pow(d,2),0.5));
	
	return newPeriod;
}

void SpringDot::checkDirection()
{
	int currentAddress = dot->fLEDs.entry(0)->me->address;
	
	bool currentDirection = dot->direction;
	
	if (currentAddress == 0)
	{
		if (currentDirection == 0)
		{
			dot->switchDirection();
		}
	}
	
	if (currentAddress == 31)
	{
		if (currentDirection == 1)
		{
			dot->switchDirection();
		}
	}
}

OscillatingDots::OscillatingDots()
{
	addFoo(new SpringDot(LITColor.red,16,1));
	addFoo(new SpringDot(LITColor.green,15,0));
	
	addFoo(new SpringDot(LITColor.blue,8,0));
}


























