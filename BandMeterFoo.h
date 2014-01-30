//	########################################################################

//  BandMeterFoo.h

//	10/9/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__BandMeterFoo__
#define __LIT_Headband_Simulator__BandMeterFoo__

#include "Foo.h"

class BandMeterFoo : public Foo
{
public:
	BandMeterFoo();
	BandMeterFoo(int band, Color aColor);
	BandMeterFoo(int band, Color aColor, int aDenominator);
	
	int band;
	
	Color bandColor;
	
	int denominator;
	
	void drawLine();
	
	
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




#endif


