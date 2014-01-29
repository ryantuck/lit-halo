//	########################################################################

//  InProgressCustomFoos.h

//	8/23/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__InProgressCustomFoos__
#define __LIT_Headband_Simulator__InProgressCustomFoos__

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

class MeterWithFlash : public Foo
{
public:
	MeterWithFlash(int aBand, Color aColor);
	void listen();
	int band;
};

class DotFlash : public Foo
{
public:
	DotFlash(int addr);
	void shine();
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

class SixDots : public Foo
{
public:
	SixDots();
	void listen();
	
	bool switcher;
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

class TwoLines : public Foo
{
public:
	TwoLines();
	void checkForOverlap();
	
	bool areSameColor;
	
	AddressedLED* head1;
	AddressedLED* tail2;
	
};




#endif







































