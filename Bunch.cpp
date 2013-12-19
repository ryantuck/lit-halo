//	########################################################################

//  Bunch.cpp

//	11/24/13

//	########################################################################

#include "Bunch.h"

Bunch::Bunch()
{
	MovingFoo* mover = new MovingFoo;
	addFoo(mover);
	
	index = 0;
	
	for (int n=0;n<8;n++)
	{
		mover->addLEDs(*LITColor.colorList[index], maxBrightness, 4*n, 4*n);
	}
	
	Step<MovingFoo>* aStep = new Step<MovingFoo>;
	aStep->period = 2;
	aStep->fnPtr = &MovingFoo::move;
	mover->addStep(aStep);
	
	Step<Bunch>* listen = new Step<Bunch>;
	listen->fnPtr = &Bunch::listenUp;
	addStep(listen);
	
}

void Bunch::listenUp()
{
	if (audio.beatJustDetected(1))
	{
		index = updateValue(index, up, 0, 6, cycles);
		
		for (int n=0;n<foos.entry(0)->me->countLEDs();n++)
		{
			foos.entry(0)->me->fLEDs.entry(n)->me->color.setColor(*LITColor.colorList[index]);
		}
	}
}