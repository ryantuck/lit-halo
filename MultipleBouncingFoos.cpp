//	########################################################################

//  MultipleBouncingFoos.cpp

//	8/5/13

//	########################################################################

#include "MultipleBouncingFoos.h"

MultipleBouncingFoo::MultipleBouncingFoo()
{	
	for (int n=0;n<4;n++)
	{
		Foo* aFoo = new Foo;
		aFoo->addLEDs(*LITColor.colorList[n], maxBrightness, n*8, n*8);
		aFoo->direction = rand()%2;
		aFoo->period = n+1;
		addFoo(aFoo);
	}
}


void MultipleBouncingFoo::update()
{	
	for (int n=0;n<countFoos();n++)
	{
		int addr1 = myFooList.entry(n)->me->myLEDList.entry(0)->me->address;
		bool dir1 = myFooList.entry(n)->me->direction;
		int p1	  = myFooList.entry(n)->me->period;
		
		for (int p=n+1;p<countFoos();p++)
		{
			int addr2 = myFooList.entry(p)->me->myLEDList.entry(0)->me->address;
			bool dir2 = myFooList.entry(p)->me->direction;
			int p2	  = myFooList.entry(p)->me->period;
			
			if (addr1 < 2 && addr2 > 29) addr1 += 32;
			if (addr2 < 2 && addr1 > 29) addr2 += 32;
			
			
			if (addr1 == addr2)		//	overlapping
			{
				if (dir1 == dir2)	//	same direction
				{
					if (p1 > p2)
					{
						myFooList.entry(p)->me->switchDirection();
						myFooList.entry(n)->me->period = p2;
						myFooList.entry(p)->me->period = p1;
					}
					else if (p1 < p2)
					{
						myFooList.entry(n)->me->switchDirection();
						myFooList.entry(n)->me->period = p2;
						myFooList.entry(p)->me->period = p1;
					}
				}
				else				//	different direction
				{
					myFooList.entry(n)->me->switchDirection();
					myFooList.entry(p)->me->switchDirection();
					myFooList.entry(n)->me->period = p2;
					myFooList.entry(p)->me->period = p1;
				}
			}
			else if (addr1+1 == addr2 || addr1-1 == addr2)	// adjacent
			{
				// needs an exception case for 32/0
				
				if (dir1 == dir2)		// same direction
				{
					if (p1 > p2)
					{
						myFooList.entry(p)->me->switchDirection();
						myFooList.entry(n)->me->period = p2;
						myFooList.entry(p)->me->period = p1;
					}
					else if (p1 < p2)
					{
						myFooList.entry(n)->me->switchDirection();
						myFooList.entry(n)->me->period = p2;
						myFooList.entry(p)->me->period = p1;
					}
				}
				
				else if (addr1 < addr2)		// different directions
				{
					if (dir1)
					{
						myFooList.entry(n)->me->switchDirection();
						myFooList.entry(p)->me->switchDirection();
						myFooList.entry(n)->me->period = p2;
						myFooList.entry(p)->me->period = p1;
					}
				}
				else if (addr1 > addr2)		// different directions
				{
					if (dir2)
					{
						myFooList.entry(n)->me->switchDirection();
						myFooList.entry(p)->me->switchDirection();
						myFooList.entry(n)->me->period = p2;
						myFooList.entry(p)->me->period = p1;
					}
				}
			}
			else if (addr1 + 2 == addr2 || addr1 - 2 == addr2)
			{
				if (myFooList.entry(n)->me->canUpdate() && myFooList.entry(p)->me->canUpdate())
				{
					if (dir1 != dir2)
					{
						if (addr1 < addr2)
						{
							if (dir1)
							{
								myFooList.entry(p)->me->periodCounter = 0;
							}
						}
						else if (addr1 > addr2)
						{
							if (dir2)
							{
								myFooList.entry(n)->me->periodCounter = 0;
							}
						}
					}
				}
			}
		}
	}
}













