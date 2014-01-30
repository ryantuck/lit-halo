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
	if (audio.beatJustDetected(1))
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


PairHolder::PairHolder()
{
	DotPair* x1 = new DotPair(true);
	DotPair* x2 = new DotPair(false);
	addFoo(x1);
	addFoo(x2);
	
}


SpeedChangerDot::SpeedChangerDot(Color aColor, int start, bool increasing)
{
	repeats = false;
	
	addLEDs(aColor, maxBrightness, start, start);
	addStepWithFunction(&SpeedChangerDot::iterate, 1, 35);
	isIncreasing = increasing;
	
	direction	= up;
	pCounter	= 0;
	mCounter	= 0;
	
	if (isIncreasing)
	{
		per	= 1;
		mov	= 5;
	}
	else
	{
		per	= 5;
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

DotPair::DotPair(bool start)
{
	startAtZero = start;
	addStepWithFunction(&DotPair::checkForFoos, 1);
	index = 0;
}

void DotPair::checkForFoos()
{
	if (!hasFoos())
	{
		int s = 16;
		if (startAtZero) s = 0;
		startAtZero = !startAtZero;
		
		index = updateValue(index, up, 0, 5, cycles);
		int index2 = updateValueBy(index, up, 2, 0, 5, cycles);
		
		SpeedChangerDot* a = new SpeedChangerDot(*LITColor.colorList[index],s,true);
		SpeedChangerDot* b = new SpeedChangerDot(*LITColor.colorList[index2],s,false);

		addFoo(a);
		addFoo(b);
	}
}




























