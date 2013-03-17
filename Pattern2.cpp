//
//  Pattern2.cpp
//  LIT-Source
//
//  Created by Ryan Tuck on 3/15/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "Pattern2.h"


Pattern2::Pattern2()
{
	createSequencesArray(1);
	
	sequences[0] = new SeqCycleColor;
}