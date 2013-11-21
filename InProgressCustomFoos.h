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



#endif


