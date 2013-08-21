//	########################################################################

//  MultipleBouncingFoos.cpp

//	8/5/13

//	########################################################################

#include "MultipleBouncingFoos.h"

MultipleBouncingFoo::MultipleBouncingFoo()
{	
	for (int n=0;n<4;n++)
	{
		MovingFoo* aFoo = new MovingFoo;
		aFoo->addLEDs(*LITColor.colorList[n], maxBrightness, n*8, n*8);
		Step<MovingFoo>* aStep = new Step<MovingFoo>;
		aStep->fnPtr	= &MovingFoo::move;
		aStep->period	= n+1;
		aFoo->addStep(aStep);
		aFoo->direction = 1;
		addFoo(aFoo);
	}
	
	Step<MultipleBouncingFoo>* myStep = new Step<MultipleBouncingFoo>;
	myStep->fnPtr = &MultipleBouncingFoo::checkForBounces;
	addStep(myStep);
}


void MultipleBouncingFoo::checkForBounces()
{
	for (int n=0;n<countFoos();n++)
	{
		MovingFoo*	fooN	= (MovingFoo*)foos.entry(n)->me;
		Step<Foo>*	stepN	= fooN->steps.entry(0)->me;
		int			addr1	= fooN->fLEDs.entry(0)->me->address;
		bool		dir1	= fooN->direction;
		int			p1		= stepN->period;
		
		for (int p=n+1;p<countFoos();p++)
		{
			MovingFoo*	fooP	= (MovingFoo*)foos.entry(p)->me;
			Step<Foo>*	stepP	= fooP->steps.entry(0)->me;	
			int			addr2	= fooP->fLEDs.entry(0)->me->address;
			bool		dir2	= fooP->direction;
			int			p2		= stepP->period;
			
			if (addr1 < 2 && addr2 > 29) addr1 += 32;
			if (addr2 < 2 && addr1 > 29) addr2 += 32;
			
			
			if (addr1 == addr2)		//	overlapping
			{
				if (dir1 == dir2)	//	same direction
				{
					if (p1 > p2)
					{
						fooP->switchDirection();
						stepN->period = p2;
						stepP->period = p1;
					}
					else if (p1 < p2)
					{
						fooN->switchDirection();
						stepN->period = p2;
						stepP->period = p1;
					}
				}
				else				//	different direction
				{
					fooN->switchDirection();
					fooP->switchDirection();
					stepN->period = p2;
					stepP->period = p1;
				}
			}
			else if (addr1+1 == addr2 || addr1-1 == addr2)	// adjacent
			{
				// needs an exception case for 32/0
				
				if (dir1 == dir2)		// same direction
				{
					if (p1 > p2)
					{
						fooP->switchDirection();
						stepN->period = p2;
						stepP->period = p1;
					}
					else if (p1 < p2)
					{
						fooN->switchDirection();
						stepN->period = p2;
						stepP->period = p1;
					}
				}
				
				else if (addr1 < addr2)		// different directions
				{
					if (dir1)
					{
						fooN->switchDirection();
						fooP->switchDirection();
						stepN->period = p2;
						stepP->period = p1;
					}
				}
				else if (addr1 > addr2)		// different directions
				{
					if (dir2)
					{
						fooN->switchDirection();
						fooP->switchDirection();
						stepN->period = p2;
						stepP->period = p1;
					}
				}
			}
			else if (addr1 + 2 == addr2 || addr1 - 2 == addr2)
			{
				if (stepN->canUpdate() && stepP->canUpdate())
				{
					if (dir1 != dir2)
					{
						if (addr1 < addr2)
						{
							if (dir1)
							{
								stepP->periodCounter = 0;
							}
						}
						else if (addr1 > addr2)
						{
							if (dir2)
							{
								stepN->periodCounter = 0;
							}
						}
					}
				}
			}
		}
	}
}













