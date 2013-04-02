//
//  Pattern10.h
//  LITheadband
//
//  Created by Daniel Kern on 3/21/13.
//  Copyright (c) 2013 Daniel Kern. All rights reserved.
//
//  created by Kern

#ifndef __LITheadband__Pattern10__
#define __LITheadband__Pattern10__

#include "Pattern.h"
#include "CustomSequences.h"

class Pattern10 : public Pattern
{
public:
	Pattern10();
    void update();
    
    int state;
    int randomTime;
    int previousTime;
    
};

#endif /* defined(__LITheadband__Pattern10__) */
