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

class AllWhite : public Foo
{
public:
	AllWhite();
};

class Bunch : public MovingFoo
{
public:
	Bunch();
	void listenUp();
	
	int index;
	
};

class MovingSwitcher : public Foo
{
public:
	MovingSwitcher();
	void listenUp();
};

class BrightnessFrequency : public Foo
{
public:
	BrightnessFrequency();
	BrightnessFrequency(int aBand,Color aColor,int aStart);
	void listenUp();
	
	int band;
	int start;
};

class BF4 : public Foo
{
public:
	BF4();
};

class BattChecker : public Foo
{
public:
	BattChecker();
	void checkBatt();
};

class BinaryValue : public Foo
{
public:
	BinaryValue();
	BinaryValue(int aStart);
	void cycle();
	void display();
	
	void changeLEDs(int newVal);
	
	int val;
	int start;
};

class DoubleMonitor : public Foo
{
public:
	DoubleMonitor();
	void checkValues();
};

class VarLengthBands : public Foo
{
public:
	VarLengthBands();
	void changeLengths();
};


#endif







































