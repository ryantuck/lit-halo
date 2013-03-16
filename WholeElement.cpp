//
//  WholeElement.cpp
//  LITheadband
//
//  Created by Daniel Kern on 3/15/13.
//  Copyright (c) 2013 Daniel Kern. All rights reserved.
//

#include "WholeElement.h"

WholeElement::WholeElement()
{
    createSegmentsArray(16);
    
    for(int n = 0; n < maxSegments; n++)
    {
        segments[n]->color.setColor(LITColor.white);
        segments[n]->length	= 1;
        segments[n]->start	= n;
    }
    
    layer		= 1;
    rate		= 1;
    brightness	= 127;
    io = 1;
}
		
