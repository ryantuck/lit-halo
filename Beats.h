//	########################################################################

//  Beats.h

//	3/2/14

//	########################################################################

#ifndef __litHeadbandSimulator__Beats__
#define __litHeadbandSimulator__Beats__

#define NUMPOINTS 100

#include "Arduino.h"

class Beats
{
public:
	Beats();
	
	byte pointLength;
	byte derivativeLimit;
	byte points[NUMPOINTS];
	
	bool detected();
	void addPoint(int newPoint);
	
	byte currentValue();
	byte lastValue();
	byte currentDerivative();
	
	byte midPoint();
	byte derivativeMidPoint();
};



#endif


