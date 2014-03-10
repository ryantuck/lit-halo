//	########################################################################

//  Strobe.h

//	3/10/14

//	########################################################################

#ifndef __litHeadbandSimulator__Strobe__
#define __litHeadbandSimulator__Strobe__

#include "Foo.h"

class Strobe : public Foo
{
public:
	Strobe();
	
	byte strobePeriod;
	
	byte colorCounter;
	
	void flashOn();
	void flashOff();
};

#endif


