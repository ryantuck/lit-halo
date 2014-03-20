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
}

// ========================================================================

FadinDubbyBowz2::FadinDubbyBowz2()
{
	addStepWithFunction(&FadinDubbyBowz2::checkMyShit, 1);
	
    
	addFoo(new DoubleRainbow);
    //addFoo(new StillEvenlySpaced(LITColor.yellow, 16, 0));
    addFoo(new Sparkle);
   
    
	
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
	{
		// set brightness of ES to max brightness
		for (int n=0;n<es->countLEDs();n++)
		{
			es->fLEDs.entry(n)->me->brightness = maxBrightness;
           
		}
         Serial.println("beat 2 detected");
	}
	else
	{
		// reduce brightness
		for (int n=0;n<es->countLEDs();n++)
		{
			es->fLEDs.entry(n)->me->brightness *= .5;
            es->fLEDs.entry(n)->me->brightness *= .5;
            Serial.println(es->fLEDs.entry(n)->me->brightness);
            
		}
        Serial.println("beat 2 not detected");
	}
}

FountainHead::FountainHead()
{
    Foo* a = new Foo;
    Foo* b = new Foo;
    a->addLEDs(LITColor.magenta, maxBrightness, 0, 15);
    b->addLEDs(LITColor.yellow, maxBrightness, 16, 31);
    
    addFoo(a);
    addFoo(b);
    
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



































