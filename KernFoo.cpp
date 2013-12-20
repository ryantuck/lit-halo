//
//  KernFoo.cpp
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 8/12/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "KernFoo.h"

KernFoo::KernFoo()
{
    addLEDs(LITColor.red, maxBrightness, 2, 7);
	
	Foo* aFoo = new Foo;
	aFoo->addLEDs(LITColor.pink, maxBrightness, 3, 10);
	//aFoo->direction = 1;
	addFoo(aFoo);
	
	Step<KernFoo>* aStep = new Step<KernFoo>;
	
	aStep->fnPtr = &MovingFoo::moveLeft;
	
	addStep(aStep);
	//aFoo->addStep(aStep);
	
	aStep->period = 5;
}

//void KernFoo::moveLeft()
//{
//	move(1);
//}

