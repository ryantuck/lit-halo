//	########################################################################

//  InProgressCustomFoos.h

//	8/23/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__InProgressCustomFoos__
#define __LIT_Headband_Simulator__InProgressCustomFoos__

#include "Foo.h"
#include "MovingFoo.h"
#include "ListenerFoo.h"
#include "EphemeralSnakesFoo.h"
#include "RainbowLine.h"
#include <math.h>
#include "LITFunctions.h"
#include "SystemMonitors.h"

#include "Stats.h"


class TestingFoo : public Foo
{
public:
	TestingFoo();
	int counter;
	void checkForSwitch();
};


class DoubleRainbow : public MovingFoo
{
public:
	DoubleRainbow();
};

class BackgroundStepper : public MovingFoo
{
public:
	BackgroundStepper();
};

class Sparkle : public Foo
{
public:
	Sparkle();
	void flicker();
	void changeColor();
	
	int index;
};

class Pulsater : public Foo
{
public:
	Pulsater();
	void upBrightness();
	void downBrightness();
};

class ListenerWithBunch : public Foo
{
public:
	ListenerWithBunch();
	void listenUp();
};

class FiniteBunch : public MovingFoo
{
public:
	FiniteBunch();
};

class DRwithListener : public Foo
{
public:
	DRwithListener();
};

class SparkleWithListener : public Sparkle
{
public:
	SparkleWithListener();
	void changeColor();
	
	int index;
};

class BigAudioTester : public Foo
{
public:
	BigAudioTester();
	void collect1KDataPoints();
	void displayData();
	void serialPrintData();
	void setUpLEDs();
	
	int spectrumData[7];
	int count;
	int rollingIndex;
};

class BinaryTester : public Foo
{
public:
	BinaryTester();
	void increment();
	
	int number;
};

class VarianceTester : public Foo
{
public:
	VarianceTester(int aBand);
	void increment();
	void computeVariance();
	void resetValues();
	
	int dataPoints[100];
	
	double	variance;
	int		index;
	int		band;
	double	avg;
	
};

class EverythingTester : public Foo
{
public:
	EverythingTester();
	void collectData();
	void displayData();
	void updateParameters();
	void changeFoos();
	
	int numSamples;
	int sampleCount;
	
	int potIndex;
	int brIndex;
	int numIndex;
	
	int spectrumData[7];
	
	Stats* stats[7];
};

class BeatCollector : public Foo
{
public:
	BeatCollector();
	
	
	void stopLight();
	void collectData();
	void printData();
	
	int sampleCount;
	int lightCounter;
	int dataPoints;
	
	byte specData[7][100];
	
};

class FullSongListener : public Foo
{
public:
	FullSongListener();
	
	void collectData();
};

class RedGreenMover : public Foo
{
public:
	RedGreenMover();
	
	
};

class RedGreenPulser : public Foo
{
public:
	RedGreenPulser();
	
	void redUpGreenDown();
	void redDownGreenUp();
	
	int pulseCounter;
};

class RedGreenAlternater : public Foo
{
public:
	RedGreenAlternater();
	
	void aUp();
	void bUp();
	
	void add1Up();
	void add2Up();
	
	int add1;
	int add2;
};

class ChristmasSnakes : public Foo
{
public:
	ChristmasSnakes();
	
	void checkForNoSnakes();
	
	int numSnakes;
	
	int count;
	
	int baseCycler;
};

class ChristmasSparkler : public Foo
{
public:
	ChristmasSparkler();
	
	void newSparkle();
	void stall();
	bool checkAddresses(int x);
	
	Color rgw[3];
	
	int totalSparkles;
	
	int colorCount;
};

class InAndOutFader : public Foo
{
public:
	InAndOutFader(Color aColor, int addr);
	
	void getBrighter();
	
	void dimDown();
	
	void fade();
	
	int totalIterations;
};

class JoshFoo : public MovingFoo
{
public:
	JoshFoo();
	
	void changeColor();
	
	int colorIndex;
};

class TwoMovers : public Foo
{
public:
	TwoMovers();
};

class RainbowShooter : public Foo
{
public:
	RainbowShooter();
	
	void addNewDot();
	
	int colorCount;
};

class SwitchingDR : public Foo
{
public:
	SwitchingDR();
	
	void checkers();
};

#endif







































