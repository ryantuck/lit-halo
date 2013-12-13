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

class MultiParticleEvent : public Foo
{
public:
	MultiParticleEvent();
	
	int counter;
	
	void checkForAllOverlap();
};

class AListener : public Foo
{
public:
	AListener();
	
	void listen();

};

class PulseFromCenter : public Foo
{
public:
	PulseFromCenter();
	
	int length;
	
	void checkForLength();
};

class BandMeter : public Foo
{
public:
	BandMeter();
	
	int length;
	
	int band;
	
	void adjustLengthForAudio();
	
};

class RainbowPulser: public Foo
{
public:
	RainbowPulser();
	
	int counter;
	bool isIncreasing;
	
	void drawNewLine();
};

class Alternater: public MovingFoo
{
public:
	Alternater();
};

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
	
	byte specData[7][120];
	
};

class FullSongListener : public Foo
{
public:
	FullSongListener();
	
	void collectData();
};


#endif







































