//	########################################################################

//  TwoColorParticleJam.h

//	12/19/13

//	########################################################################

#ifndef __litHeadbandSimulator__TwoColorParticleJam__
#define __litHeadbandSimulator__TwoColorParticleJam__

#include "Foo.h"
#include "MovingFoo.h"

class TwoColorParticleJam : public Foo
{
public:
	TwoColorParticleJam(Color c1, Color c2);
	
	void changeColors(Color c1, Color c2);
};

class TCPJwL : public Foo
{
public:
	TCPJwL();
	void listen();
	
	int baseCycler;
};


#endif


