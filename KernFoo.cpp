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
    setBlock(LITColor.red, maxBrightness, 2, 7);
    
    addItem();
    foos[0]->setBlock(LITColor.pink, maxBrightness, 3, 10);
    foos[0]->direction = 1;
    
    
}
