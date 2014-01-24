//	########################################################################

//  InProgressCustomFoos.cpp

//	8/23/13

//	########################################################################

#include "InProgressCustomFoos.h"



ListenerWithBunch::ListenerWithBunch()
{
	Step<ListenerWithBunch>* myStep = new Step<ListenerWithBunch>;
	myStep->fnPtr = &ListenerWithBunch::listenUp;
	addStep(myStep);
}

void ListenerWithBunch::listenUp()
{
	if (audio.beatJustDetected(1))
	{
		FiniteBunch* fb = new FiniteBunch;
		addFoo(fb);
	}
}

FiniteBunch::FiniteBunch()
{
	for (int n=0;n<8;n++)
	{
		addLEDs(LITColor.white, maxBrightness, 4*n, 4*n);
	}
	
	layer = 2;
	
	repeats = false;
	
	Step<MovingFoo>* myStep = new Step<MovingFoo>;
	myStep->fnPtr = &MovingFoo::move;
	myStep->count = 32;
	addStep(myStep);
}





























































