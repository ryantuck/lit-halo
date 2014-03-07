//	########################################################################

//  FooManager.cpp

//	8/21/13

//	########################################################################

#include "FooManager.h"

FooManager::FooManager()
{
	foo			= new BatteryFoo;
	foodex		= 0;
	maxFoodex	= 1;
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
	foo = new DoubleRainbow;
}

//  ================================================================
//  ================================================================
//  ================================================================


MasterFooManager::MasterFooManager()
{
	maxFoodex = 5;
}

void MasterFooManager::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new RainbowPulser;
			break;
		case 1:
			foo = new MultipleBouncingFoo;
			break;
		case 2:
			foo = new EvenEphemSnakes;
			break;
		case 3:
			foo = new Bunch;
			break;
		case 4:
			foo = new TCPJwL();
			break;
		case 5:
			foo = new Pulse4;
			break;
	}
}

//  ================================================================

DevFooManager::DevFooManager()
{
	maxFoodex = 13;
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
            foo = new Sparkle;
            break;
		case 7:
			foo = new FadinDubbyBowz;
			break;
		case 8:
			foo = new Strobe;
			break;
		case 9:
			foo = new DoubleRainbowPulser;
			break;
		case 10:
			foo = new BackgroundCycler;
			break;
		case 11:
			foo = new CloseColorDots(8);
			break;
		case 12:
			foo = new ExplosionHolder;
			break;
		case 13:
			foo = new FanOut;
			break;
	}
}

//  ================================================================
//  ================================================================
//  ================================================================

//  ================================================================

DevFooManager2::DevFooManager2()
{
	maxFoodex = 3;
}

void DevFooManager2::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new TwoColorParticleJam(LITColor.red,LITColor.cyan);
			break;
		case 1:
			foo = new FireworksHolder;
			break;
		case 2:
			foo = new FireworksHolder;
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

//  ================================================================

SystemTests::SystemTests()
{
    maxFoodex = 2;
}

void SystemTests::createNewFoo(int index)
{
	// commented this out to run a quick test on BeatCollector.
	// for some reason, bc won't work when one of many foos.
	// probably has something to do with huge bc memory usage.
	
//    switch (index)
//    {
//        case 0:
//            foo = new VarianceTester(0);
//            break;
//        case 1:
//			foo = new DoubleMonitor;
//			break;
//        case 2:
//            foo = new BeatCollector;
//            break;
//            
//    }
	foo = new EverythingTester;
}

//  ================================================================

ContinuousOutput::ContinuousOutput()
{
	maxFoodex = 1;
}

void ContinuousOutput::createNewFoo(int index)
{
	foo = new ContinuousListener;
}

//  ================================================================

BeatTestingManager::BeatTestingManager()
{
	maxFoodex = 6;
}

void BeatTestingManager::createNewFoo(int index)
{
	foo = new MeterWithFlash(index, *LITColor.spectrum[index]);
}

//  ================================================================
//  ================================================================
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









