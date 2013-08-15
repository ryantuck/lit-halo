//
//  Pattern0.cpp
//  LIT-Source
//
//  Created by Ryan Tuck on 3/13/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "Pattern0.h"

Pattern0::Pattern0()
{
	createSequencesArray(1);
	
	sequences[0] = new SeqLowBatt;
}