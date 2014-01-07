//	########################################################################

//  FooManager.cpp

//	8/21/13

//	########################################################################

#include "FooManager.h"

FooManager::FooManager()
{
	foo			= NULL;
	foodex		= 0;
	maxFoodex	= 8;
	
	updateFoo(foodex);
}

void FooManager::update()
{
	updateFoo(foodex);
}

void FooManager::updateFoo(int index)
{
	if (foo)
	{
		delete foo;
		foo = NULL;
	}
	
	createNewFoo(index);
}

void FooManager::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new DoubleRainbow;
			break;
		case 1:
			foo = new MultipleBouncingFoo;
			break;
		case 2:
			foo = new Sparkle;
			break;
		case 3:
			foo = new BF4;
			break;
		case 4:
			foo = new Bunch;
			break;
		case 5:
			foo = new EvenEphemSnakes;
			break;
		case 6:
			foo = new CirclesFoo;
			break;
	}
}

//  ================================================================

DevFooManager::DevFooManager()
{
	maxFoodex = 7;
}

void DevFooManager::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new TwoColorParticleJam(LITColor.red,LITColor.cyan);
			break;
		case 1:
			foo = new AllOn(LITColor.cyan);
			break;
		case 2:
			foo = new Pulse4;
			break;
		case 3:
			foo = new RainbowPulser;
			break;
        case 4:
            foo = new HiToLowBrightnessTrail(LITColor.green,10,10,0);
            break;
        case 5:
            foo = new DoubleRainbow;
            break;
        case 6:
            foo = new TestingFoo;
            break;
        case 7:
            foo = new BackgroundStepper;
            break;
        case 8:
            foo = new Sparkle;
            break;
	}
}

//  ================================================================

BandFooManager::BandFooManager()
{
	maxFoodex = 6;
}

void BandFooManager::createNewFoo(int index)
{
	foo = new BandMeterFoo(index,*LITColor.spectrum[index]);
}

SystemTests::SystemTests()
{
    maxFoodex = 2;
}

void SystemTests::createNewFoo(int index)
{
    switch (index)
    {
        case 0:
            foo = new VarianceTester(0);
            break;
        case 1:
			foo = new DoubleMonitor;
			break;
        case 2:
            foo = new BeatCollector;
            break;
            
    }
}

//  ================================================================

ChristmasManager::ChristmasManager()
{
	maxFoodex = 4;
}

void ChristmasManager::createNewFoo(int index)
{
	switch(index)
	{
		case 0:
			foo = new RedGreenMover();
			break;
		case 1:
			foo = new RedGreenAlternater();
			break;
		case 2:
			foo = new RedGreenPulser();
			break;
		case 3:
			foo = new ChristmasSnakes();
			break;
		case 4:
			foo = new ChristmasSparkler();
			break;
	}
}


//  ================================================================

StillManager::StillManager()
{
	maxFoodex = 7;
}

void StillManager::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new StillRainbow;
			break;
		case 1:
			foo = new StillDoubleRainbow;
			break;
		case 2:
			foo = new AllOn(LITColor.white);
			break;
		case 3:
			foo = new AllOn(LITColor.green);
			break;
		case 4:
			foo = new AllOn(LITColor.yellow);
			break;
		case 5:
			foo = new StillEvenlySpaced(LITColor.magenta,4,0);
			break;
		case 6:
			foo = new StillEvenlySpaced(LITColor.cyan,16,0);
			break;
		case 7:
			foo = new StillDubz;
			break;
	}
}


















