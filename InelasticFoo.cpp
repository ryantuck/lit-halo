//	########################################################################

//  InelasticFoo.cpp

//	8/8/13

//	########################################################################

#include "InelasticFoo.h"

InelasticFoo::InelasticFoo()
{
	for (int n=0;n<4;n++)
	{
		addItem();
		foos[n]->setBlock(*LITColor.colorList[n], maxBrightness, n*8, n*8);
		foos[n]->direction = rand()%2;
		foos[n]->period = n+1;
	}
}

void InelasticFoo::update()
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
		}
	}
}


