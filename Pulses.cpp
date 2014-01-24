//	########################################################################

//  Pulses.cpp

//	12/19/13

//	########################################################################

#include "Pulses.h"

Pulse4::Pulse4()
{
	orientation = 0;
	colIndex	= 0;
	
	addStepWithFunction<Pulse4>(&Pulse4::runIt,1);
}

void Pulse4::runIt()
{
	if (!hasFoos())
	{
		// switch orientation
		orientation = !orientation;
		
		// build 4 snakes
		for (int a=0;a<2;a++)
		{
			for (int b=0;b<2;b++)
			{
				int start	= 0;
				bool dir	= 0;
				
				if (orientation)
				{
					start = 7 + a + 16*b;
					dir = (bool)a;
				}
				else
				{
					start = 15*a + 16*b;
					dir = (bool)!a;
				}
				
				EphemeralSnake* x = new EphemeralSnake(start,
													   8,
													   dir,
													   LITColor.colorList[colIndex]);
				addFoo(x);
			}
		}
		
		colIndex = updateValue(colIndex, up, 0, 5, cycles);
	}
}

