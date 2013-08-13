//	########################################################################

//  MultipleBouncingFoos.cpp

//	8/5/13

//	########################################################################

#include "MultipleBouncingFoos.h"

MultipleBouncingFoo::MultipleBouncingFoo()
{
	for (int n=0;n<4;n++)
	{
		addItem();
		foos[n]->setBlock(*LITColor.colorList[n], maxBrightness, n*8, n*8);
		foos[n]->direction = rand()%2;
		foos[n]->period = n+1;
	}
}


void MultipleBouncingFoo::update()
{	
	for (int n=0;n<numberOfFoos;n++)
	{
		int	addr1 = foos[n]->fLEDs[0]->address;
		bool dir1 = foos[n]->direction;
		int	   p1 = foos[n]->period;
		
		for (int p=n+1;p<numberOfFoos;p++)
		{
			int addr2 = foos[p]->fLEDs[0]->address;
			bool dir2 = foos[p]->direction;
			int	   p2 = foos[p]->period;
			
			if (addr1 < 2 && addr2 > 29) addr1 += 32;
			if (addr2 < 2 && addr1 > 29) addr2 += 32;
			
			
			if (addr1 == addr2)		//	overlapping
			{
				if (dir1 == dir2)	//	same direction
				{
					if (p1 > p2)
					{
						foos[p]->switchDirection();
						foos[n]->period = p2;
						foos[p]->period = p1;
						
					}
					else if (p1 < p2)
					{
						foos[n]->switchDirection();
						foos[n]->period = p2;
						foos[p]->period = p1;
					}
				}
				else				//	different direction
				{
					foos[n]->switchDirection();
					foos[p]->switchDirection();
					foos[n]->period = p2;
					foos[p]->period = p1;
				}
			}
			else if (addr1+1 == addr2 || addr1-1 == addr2)	// adjacent
			{
				// needs an exception case for 32/0
				
				if (dir1 == dir2)		// same direction
				{
					if (p1 > p2)
					{
						foos[p]->switchDirection();
						foos[n]->period = p2;
						foos[p]->period = p1;
					}
					else if (p1 < p2)
					{
						foos[n]->switchDirection();
						foos[n]->period = p2;
						foos[p]->period = p1;
					}
				}
				
				else if (addr1 < addr2)		// different directions
				{
					if (dir1)
					{
						foos[n]->switchDirection();
						foos[p]->switchDirection();
						foos[n]->period = p2;
						foos[p]->period = p1;
					}
				}
				else if (addr1 > addr2)		// different directions
				{
					if (dir2)
					{
						foos[n]->switchDirection();
						foos[p]->switchDirection();
						foos[n]->period = p2;
						foos[p]->period = p1;
					}
				}
			}
			else if (addr1 + 2 == addr2 || addr1 - 2 == addr2)
			{
				if (foos[n]->canUpdate() && foos[p]->canUpdate())
				{
					if (dir1 != dir2)
					{
						if (addr1 < addr2)
						{
							if (dir1)
							{
								foos[p]->periodCounter = 0;
							}
						}
						else if (addr1 > addr2)
						{
							if (dir2)
							{
								foos[n]->periodCounter = 0;
							}
						}
					}
				}
			}
		}
	}
}













