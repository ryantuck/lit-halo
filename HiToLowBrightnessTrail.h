//
//  HiToLowBrightnessTrail.h
//  litHeadbandSimulator
//
//  Created by Alyssa Lerch on 12/20/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#ifndef __litHeadbandSimulator__HiToLowBrightnessTrail__
#define __litHeadbandSimulator__HiToLowBrightnessTrail__

#include "Foo.h"
#include "LITFunctions.h"

class HiToLowBrightnessTrail : public Foo
{
public:
    HiToLowBrightnessTrail(Color aColor,
                           int length,
                           int start,
                           bool direction);
};


#endif
