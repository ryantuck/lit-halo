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
			foo = new KernFoo;
			break;
		case 1:
			foo = new StepFoo1;
			break;
		case 2:
			foo = new Foo2;
			break;
		case 3:
			foo = new LinkedFoo;
			break;
		case 4:
			foo = new RainbowFoo;
			break;
		case 5:
			foo = new EventFoo;
			break;
		case 6:
			foo = new OscillatingFoo;
			break;
		case 7:
			foo = new MultipleBouncingFoo;
			break;
		case 8:
			foo = new CirclesFoo;
			break;
	}
}

DevFooManager::DevFooManager()
{
	maxFoodex = 7;
}

void DevFooManager::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new MultipleBouncingFoo;
			break;
		case 1:
			foo = new TestingFoo;
			break;
		case 2:
			foo = new CirclesFoo;
			break;
		case 3:
			foo = new EphemeralSnakesFoo;
			break;
		case 4:
			foo = new EvenEphemSnakes;
			break;
		case 5:
			foo = new RainbowLine(32,0);
			break;
		case 6:
			foo = new ListenerFoo;
			break;
		case 7:
			foo = new BandMeterFoo;
			break;
	}
}


BandFooManager::BandFooManager()
{
	maxFoodex = 6;
}

void BandFooManager::createNewFoo(int index)
{
	foo = new BandMeterFoo(index,*LITColor.spectrum[index]);
}

MonoBandFooManager::MonoBandFooManager()
{
	maxFoodex = 6;
}

void MonoBandFooManager::createNewFoo(int index)
{
	foo = new BandMeterFoo(2,*LITColor.colorList[index],128*(index+1));
}


SingleTestManager::SingleTestManager()
{
	maxFoodex = 1;
}

void SingleTestManager::createNewFoo(int index)
{
	foo = new AllOn(LITColor.white);
}

Tests::Tests()
{
	maxFoodex = 12;
}

void Tests::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new Bunch;
			break;
		case 1:
			foo = new DoubleMonitor;
			break;
		case 2:
			foo = new BrightnessFrequency(1,LITColor.magenta,0);
			break;
		case 3:
			foo = new MovingSwitcher;
			break;
		case 4:
			foo = new BF4;
			break;
		case 5:
			foo = new AllOn(LITColor.white);
			break;
		case 6:
			foo = new VarLengthBands;
			break;
		case 7:
			foo = new DoubleRainbow;
			break;
		case 8:
			foo = new MultipleBouncingFoo(8);
			break;
		case 9:
			foo = new Sparkle;
			break;
		case 10:
			foo = new Pulsater;
			break;
		case 11:
			foo = new DRwithListener;
			break;
		case 12:
			foo = new RainbowShooter;
			break;
	}
}

AudioTester::AudioTester()
{
	maxFoodex = 1;
}

void AudioTester::createNewFoo(int index)
{
	foo = new BeatCollector;
}

BestFooManager::BestFooManager()
{
	maxFoodex = 6;
}

void BestFooManager::createNewFoo(int index)
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

VarTester::VarTester()
{
	maxFoodex = 1;
}

void VarTester::createNewFoo(int index)
{
	foo = new VarianceTester(0);
}


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


JoshManager::JoshManager()
{
	maxFoodex = 1;
}

void JoshManager::createNewFoo(int index)
{
	switch (index)
	{
		case 0:
			foo = new JoshFoo();
			break;
		case 1:
			foo = new MultipleBouncingFoo();
			break;
	}
}

BullshitManager::BullshitManager()
{
	maxFoodex = 7;
}

void BullshitManager::createNewFoo(int index)
{
	switch(index)
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
	}
}





















