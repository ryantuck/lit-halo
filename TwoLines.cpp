//	########################################################################

//  TwoLines.cpp

//	1/30/14

//	########################################################################

#include "TwoLines.h"

TwoLines::TwoLines()
{
	MovingFoo* a1 = new MovingFoo;
	MovingFoo* a2 = new MovingFoo;
	
	a1->addLEDs(LITColor.red, maxBrightness, 0, 3);
	a2->addLEDs(LITColor.blue, maxBrightness, 16, 19);
	
	a1->direction = up;
	a2->direction = down;
	
	a1->addStepWithFunction(&MovingFoo::move, 4);
	a2->addStepWithFunction(&MovingFoo::move, 4);
	
	addFoo(a1);
	addFoo(a2);
	
	head1 = a1->fLEDs.entry(3)->me;
	tail2 = a2->fLEDs.entry(3)->me;
	
	areSameColor = false;
	
	addStepWithFunction(&TwoLines::checkForOverlap, 1);
	
	addrCheck = 45; // for now
}

void TwoLines::checkForOverlap()
{
	if (head1->address == tail2->address)
	{
		if (head1->address != addrCheck)
		{
			// overlapping
			
			if (areSameColor)
			{
				// change colors to independent colors
				for (int n=0;n<4;n++)
				{
					foos.entry(0)->me->fLEDs.entry(n)->me->color.setColor(LITColor.red);
					foos.entry(1)->me->fLEDs.entry(n)->me->color.setColor(LITColor.blue);
				}
			}
			else
			{
				// make colors the same
				for (int n=0;n<4;n++)
				{
					foos.entry(0)->me->fLEDs.entry(n)->me->color.setColor(LITColor.magenta);
					foos.entry(1)->me->fLEDs.entry(n)->me->color.setColor(LITColor.magenta);
					
				}
			}
			
			areSameColor = !areSameColor;
			addrCheck = head1->address;
			
		}
	}
}


