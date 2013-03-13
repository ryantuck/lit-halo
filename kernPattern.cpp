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
	createSequencesArray(1);
	
	sequences[0] = new kernSequence;
}
