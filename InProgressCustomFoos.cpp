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

MeterWithFlash::MeterWithFlash(int aBand, Color aColor)
{
	BandMeterFoo* x = new BandMeterFoo(aBand, aColor);
	addFoo(x);
	
	band = aBand;
	
	addStepWithFunction(&MeterWithFlash::listen, 1);
}

void MeterWithFlash::listen()
{
	if (audio.beatJustDetected(band))
	{
		DotFlash* a = new DotFlash(10);
		addFoo(a);
	}
}

DotFlash::DotFlash(int addr)
{
	repeats = false;
	
	addLEDs(LITColor.white, maxBrightness, addr, addr);
	
	addStepWithFunction(&DotFlash::shine, 1, 6);
}

void DotFlash::shine()
{
	
}

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


ASlowDot::ASlowDot()
{
	MovingDot* x = new MovingDot(LITColor.green,up,0);
	addFoo(x);
	
	x->steps.entry(0)->me->period = 4;
}

SixDots::SixDots()
{
	MovingDot* a = new MovingDot(LITColor.red,down,0);
	MovingDot* b = new MovingDot(LITColor.green,down,3);
	MovingDot* c = new MovingDot(LITColor.blue,down,9);
	MovingDot* d = new MovingDot(LITColor.cyan,up,16);
	MovingDot* e = new MovingDot(LITColor.yellow,up,21);
	MovingDot* f = new MovingDot(LITColor.magenta,up,27);
	
	addFoo(a);
	addFoo(b);
	addFoo(c);
	addFoo(d);
	addFoo(e);
	addFoo(f);
	
	a->steps.entry(0)->me->period = 1;
	b->steps.entry(0)->me->period = 2;
	c->steps.entry(0)->me->period = 4;
	d->steps.entry(0)->me->period = 1;
	e->steps.entry(0)->me->period = 2;
	f->steps.entry(0)->me->period = 4;
	
	addStepWithFunction(&SixDots::listen, 1);
	
	switcher = true;
}

void SixDots::listen()
{
	if (audio.beatJustDetected(1))
	{
		for (int n=0;n<countFoos();n++)
		{
			MovingDot* x = (MovingDot*)foos.entry(n)->me;
				
			if (switcher)
			{
				x->fLEDs.entry(0)->me->color.setColor(LITColor.white);
			}
			else
			{
				int a = rand() % 6;
				x->fLEDs.entry(0)->me->color.setColor(*LITColor.colorList[a]);
			}
		}
		
		switcher = !switcher;
	}
}

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















































