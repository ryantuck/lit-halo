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

class PairHolder : public Foo
{
public:
	PairHolder();
	void checkForFoos();
	
	bool startAtZero;
	
};

class SlowingDot : public MovingFoo
{
public:
	SlowingDot(int start);
	void iterate();
	
	int sPeriod;
	int spCounter;
	int sMoves;
	int smCounter;
};

class SpeedingDot : public MovingFoo
{
public:
	SpeedingDot(int start);
	void iterate();
	
	int sPeriod;
	int spCounter;
	int sMoves;
	int smCounter;
};

class DotPair : public Foo
{
public:
	DotPair(bool start);
	void checkForFoos();
	
	bool startAtZero;
};



#endif







































