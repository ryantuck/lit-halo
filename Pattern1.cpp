//
//  Pattern1.cpp
//  LITheadband
//
//  Created by Daniel Kern on 3/11/13.
//  Copyright (c) 2013 Daniel Kern. All rights reserved.
//

#include "Pattern1.h"


Pattern1::Pattern1()
{
	maxSequences = 1;
	sequences = new Sequence*[maxSequences];
	
	sequences[0] = new kernSequence;
}