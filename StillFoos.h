//	########################################################################

//  StillFoos.h

//	1/7/14

//	########################################################################

#ifndef __litHeadbandSimulator__StillFoos__
#define __litHeadbandSimulator__StillFoos__

#include "Foo.h"
#include "RainbowLine.h"

class StillRainbow : public Foo
{
public:
	StillRainbow();
};

class StillDoubleRainbow : public Foo
{
public:
	StillDoubleRainbow();
};

class StillEvenlySpaced : public Foo
{
public:
	StillEvenlySpaced(Color aColor, int aNumber,int start);
};

class StillDubz : public Foo
{
public:
	StillDubz();
};


#endif


