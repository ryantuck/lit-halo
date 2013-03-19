//	####################################################################

//	Segment.h

//	*	Basic unit of pattern architecture.

//	####################################################################

#ifndef ____Segment__
#define ____Segment__

#include "Color.h"


class Segment
{
public:
	
	Color	color;
	byte	length;		//	1 - 16
	byte	start;		//	0 - 15
	
	//	Constructors
	Segment();
	Segment(Color newColor, byte newLength, byte newStart);
	
	void check();

	//	For testing
	void printVitals();
	
private:
	byte checkVal(byte val, byte min, byte max, bool cycles);
};

#endif
