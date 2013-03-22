//
//  SeqGlitter.h
//  LITheadband
//
//  Created by Daniel Kern on 3/21/13.
//  Copyright (c) 2013 Daniel Kern. All rights reserved.
//

#ifndef __LITheadband__SeqGlitter__
#define __LITheadband__SeqGlitter__

#include "Sequence.h"
#include "CustomElements.h"
#include "LITColor.h"

class SeqGlitter : public Sequence
{
public:
	SeqGlitter(Color newColor, int layer);
	void update();
    
    int prob_on;
    int counter;
    bool state;
    
    Color myColor;

};

#endif /* defined(__LITheadband__SeqGlitter__) */
