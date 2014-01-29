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

void TwoColorParticleJam::changeColors(Color c1, Color c2)
{
	for (int n=0;n<3;n++)
	{
		foos.entry(n)->me->fLEDs.entry(0)->me->color.setColor(c1);
	}
	
	for (int n=0;n<3;n++)
	{
		foos.entry(n+3)->me->fLEDs.entry(0)->me->color.setColor(c2);
	}
}

TCPJwL::TCPJwL()
{
	TwoColorParticleJam* x = new TwoColorParticleJam(LITColor.red,
													 LITColor.cyan);
	addFoo(x);
	
	addStepWithFunction(&TCPJwL::listen, 1);
	
	baseCycler = 0;
	
}

void TCPJwL::listen()
{
	if (audio.beatJustDetected(1))
	{
		baseCycler = updateValue(baseCycler, up, 0, 2, cycles);
		
		TwoColorParticleJam* x = (TwoColorParticleJam*)foos.entry(0)->me;
		
		int a1 = baseCycler;
		int a2 = baseCycler+3;
		
		x->changeColors(*LITColor.colorList[a1],*LITColor.colorList[a2]);
	}
}




























