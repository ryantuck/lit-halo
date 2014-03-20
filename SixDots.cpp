//	########################################################################

//  SixDots.cpp

//	1/30/14

//	########################################################################

#include "SixDots.h"

SixDots::SixDots()
{
	MovingDot* a = new MovingDot(LITColor.red,down,0);
	MovingDot* b = new MovingDot(LITColor.green,down,3);
	MovingDot* c = new MovingDot(LITColor.blue,down,9);
	MovingDot* d = new MovingDot(LITColor.cyan,up,16);
	MovingDot* e = new MovingDot(LITColor.yellow,up,21);
	MovingDot* f = new MovingDot(LITColor.magenta,up,27);
	
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
	
	addStepWithFunction(&SixDots::listen, 1);
	
	switcher = true;
}

void SixDots::listen()
{
	if (audio.beats.detected())
	{
		for (int n=0;n<countFoos();n++)
		{
			MovingDot* x = (MovingDot*)foos.entry(n)->me;
			
			if (switcher)
			{
				x->fLEDs.entry(0)->me->color.setColor(LITColor.white);
			}
			else
			{
				int a = rand() % 6;
				x->fLEDs.entry(0)->me->color.setColor(*LITColor.colorList[a]);
			}
		}
		
		switcher = !switcher;
	}
}


