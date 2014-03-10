//	########################################################################

//  InProgressCustomFoos.h

//	8/23/13

//	########################################################################

#ifndef __InProgressCustomFoos__
#define __InProgressCustomFoos__

#include "Foo.h"
#include "MovingFoo.h"
#include "EphemeralSnakesFoo.h"
#include "RainbowLine.h"
#include <math.h>
#include "LITFunctions.h"
#include "SystemMonitors.h"
#include "Stats.h"
#include "BandMeterFoo.h"
#include "InAndOutFader.h"

#include "RainbowFountain.h"
#include "RainbowPulser.h"
#include "EphemeralSnakesFoo.h"
#include "TwoColorParticleJam.h"
#include "StillFoos.h"
#include "AllSingleColors.h"


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

class SlowMovingDot : public Foo
{
public:
	SlowMovingDot();
	
	void changeEdges();
	void changeEntries();
	void changeAddresses();
	
	int back;
	int middle;
	int lead;
};

class BrightnessTest : public Foo
{
public:
	BrightnessTest();
};

class SuperSlowDot : public Foo
{
public:
	SuperSlowDot();
	
	void changeBrightness();
	void moveBack();
	
	int brIndex;
	
	int leadAddress;
	int leadIndex;
	int trailIndex;
};

class ASlowDot : public Foo
{
public:
	ASlowDot();
};

class TwoSnakes : public Foo
{
public:
	TwoSnakes();
};

class ZeroColorSwitcher : public Foo
{
public:
	ZeroColorSwitcher();
	void checkForColorTriggers();
	
	MovingFoo* thisGuy;
	
	AddressedLED* headLED;
	AddressedLED* tailLED;
	
	int colorIndex;
	bool isPassing;
};

class TenDotFaders : public Foo
{
public:
	TenDotFaders();
	void checkForFoos();
	void addTen();
};

class MovingFadingDot : public Foo
{
public:
	MovingFadingDot();
	void reduceBrightness();
	
	AddressedLED* theLED;
};

class LotsOfMovingFadingDots : public Foo
{
public:
	LotsOfMovingFadingDots();
	void checkFoos();
	
	int maxFoos;
};


class FadinDubbyBowz : public Foo
{
public:
	FadinDubbyBowz();
	
	void checkMyShit();
	
	Foo* dr;
	Foo* r1;
	Foo* r2;
};


class PairHolder : public Foo
{
public:
	PairHolder();
	void checkForFoos();
	
	bool startAtZero;
	
};



class SpeedChangerDot : public MovingFoo
{
public:
	SpeedChangerDot(Color aColor, int start, bool increasing, int longest, bool aDirection);
	void iterate();
	
	bool isIncreasing;
	int per;
	int pCounter;
	int mov;
	int mCounter;
};

class DotPair : public Foo
{
public:
	DotPair(int start, int longest, bool aDirection);
	void checkForFoos();
	
	bool startAtZero;
	int index;
	int startAddress;
	int startOffset;
	int per;
	bool direction;
};

class WhiteBrightnessTest : public Foo
{
public:
	WhiteBrightnessTest();
};

class BackgroundCycler : public Foo
{
public:
	BackgroundCycler();
	void checkForBeat();
	
	int cycler;
};

class Fireworks : public Foo
{
public:
	Fireworks(Color aColor);
	void iterate();
	
	void flashLEDs();
	void changeNumberOfLEDs();
	
	int numberOfLEDs;
	bool isIncreasing;
	
	int maxLEDs;
    
    Color myColor;
    bool location;
};

class FireworksHolder : public Foo
{
public:
    bool state;
	FireworksHolder();
	void checkMyShit();
};

class BeatMania : public Foo
{
public:
    BeatMania();
    void checkMyShit();
    void clear();
};

class Strobe : public Foo
{
public:
	Strobe();
	
	byte strobePeriod;
	
	byte colorCounter;
	
	void flashOn();
	void flashOff();
};

class CloseColorDots : public Foo
{
public:
	CloseColorDots(int number);
	
	int colorIndex;
	int maxColorIndex;
	
	void cycleThroughColors();
	void listen();
};

class Explosion : public Foo
{
public:
	Explosion();
	
	void moveAndFade();
};

class ExplosionHolder : public Foo
{
	
	// this shit causes a crash if too many beats are detected too quickly.
public:
	ExplosionHolder();
	void listen();
};


class FanOut : public Foo
{
public:
	FanOut();
	
	void fan();
};

class BeatMotionStopper : public MovingFoo
{
public:
	BeatMotionStopper();
	void checkForBeats();
	void updateMotionCount();
	
	bool motionOn;
	int mCount;
	int maxCount;
};

class AppearAndFadeEvent : public Foo
{
public:
	AppearAndFadeEvent();
	
	void checkForBeats();
};













#endif







































