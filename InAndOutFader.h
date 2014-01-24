//	########################################################################

//  InAndOutFader.h

//	1/24/14

//	########################################################################

#ifndef __litHeadbandSimulator__InAndOutFader__
#define __litHeadbandSimulator__InAndOutFader__

#include "Foo.h"
#include "LITFunctions.h"

class InAndOutFader : public Foo
{
public:
	InAndOutFader(Color aColor, int addr);
	
	void getBrighter();
	
	void dimDown();
	
	void fade();
	
	int totalIterations;
};



#endif


