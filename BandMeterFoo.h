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




#endif


