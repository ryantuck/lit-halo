//
//  kernPattern.cpp
//  LIT-Source
//
//  Created by Ryan Tuck on 3/2/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "kernPattern.h"


kernPattern::kernPattern()
{
	maxSequences = 1;
	sequences = new Sequence*[maxSequences];
	
	sequences[0] = new kernSequence;
}
