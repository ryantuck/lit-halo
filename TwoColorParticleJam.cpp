//	########################################################################

//  TwoColorParticleJam.cpp

//	12/19/13

//	########################################################################

#include "TwoColorParticleJam.h"

TwoColorParticleJam::TwoColorParticleJam(Color c1, Color c2)
{
	MovingDot* a = new MovingDot(c1,down,31);
	MovingDot* b = new MovingDot(c1,down,31);
	MovingDot* c = new MovingDot(c1,down,31);
	MovingDot* d = new MovingDot(c2,up,0);
	MovingDot* e = new MovingDot(c2,up,0);
	MovingDot* f = new MovingDot(c2,up,0);
	
	addFoo(a);
	addFoo(b);
	addFoo(c);
	addFoo(d);
	addFoo(e);
	addFoo(f);
	
	a->steps.entry(0)->me->period = 1;
	b->steps.entry(0)->me->period = 2;
	c->steps.entry(0)->me->period = 4;
	d->steps.entry(0)->me->period = 1;
	e->steps.entry(0)->me->period = 2;
	f->steps.entry(0)->me->period = 4;
}