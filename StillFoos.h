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
	StillRainbow(int aBrightness);
};

class StillDoubleRainbow : public Foo
{
public:
	StillDoubleRainbow(int aBrightness);
};

class StillEvenlySpaced : public Foo
{
public:
	StillEvenlySpaced(int aBrightness, Color aColor, int aNumber,int start);
};

class StillDubz : public Foo
{
public:
	StillDubz(int aBrightness);
};


#endif


