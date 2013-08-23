//	########################################################################

//  InProgressCustomFoos.h

//	8/23/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__InProgressCustomFoos__
#define __LIT_Headband_Simulator__InProgressCustomFoos__

#include "Foo.h"
#include "MovingFoo.h"
#include "ListenerFoo.h"
#include "EphemeralSnakesFoo.h"

class MultiParticleEvent : public Foo
{
public:
	MultiParticleEvent();
	
	int counter;
	
	void checkForAllOverlap();
};

class AListener : public Foo
{
public:
	AListener();
	
	void listen();

};

class PulseFromCenter : public Foo
{
public:
	PulseFromCenter();
	
	int length;
	
	void checkForLength();
};





#endif


