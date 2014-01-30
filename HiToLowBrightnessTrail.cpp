//
//  HiToLowBrightnessTrail.cpp
//  litHeadbandSimulator
//
//  Created by Alyssa Lerch on 12/20/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "HiToLowBrightnessTrail.h"


HiToLowBrightnessTrail::HiToLowBrightnessTrail(Color aColor,
                                               int length,
                                               int start,
                                               bool direction)
{
    for (int n=0;n<length;n++)
	{
        // get brightness ratio
		float numb = length;
		float mb = maxBrightness;
		float ratio = n/numb;
		float br = ratio * mb;
        
        // determine address of LED based on direction input
        int addr = 0;
        if (direction)  addr = start + n;
        else            addr = start - n;
        addr = checkAddress(addr);
        
		addLEDs(aColor, br, addr, addr);
	}
	
//	addStepWithFunction(&MovingFoo::moveLeft,1);
}


