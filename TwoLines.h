//	########################################################################

//  TwoLines.h

//	1/30/14

//	########################################################################

#ifndef __litHeadbandSimulator__TwoLines__
#define __litHeadbandSimulator__TwoLines__

#include "Foo.h"
#include "MovingFoo.h"

class TwoLines : public Foo
{
public:
	TwoLines();
	void checkForOverlap();
	
	bool areSameColor;
	
	AddressedLED* head1;
	AddressedLED* tail2;
	
	int addrCheck;
};




#endif


