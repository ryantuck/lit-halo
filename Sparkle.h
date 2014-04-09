//	########################################################################

//  Sparkle.h

//	1/23/14

//	########################################################################

#ifndef __litHeadbandSimulator__Sparkle__
#define __litHeadbandSimulator__Sparkle__

#include "Foo.h"
#include "LITFunctions.h"

class Sparkle : public Foo
{
public:
	Sparkle();
	void flicker();
	void changeColor();
	
	int index;
};

/////////////////////////////////////////////////////////////////////
class Sparkle2 : public Foo
{
public:
	Sparkle2();
	void flicker();
	void changeColor();
	
	int index;
};




#endif


