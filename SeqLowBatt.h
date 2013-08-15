//
//  SeqLowBatt.h
//  LIT-Source
//
//  Created by Ryan Tuck on 3/13/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#ifndef __LIT_Source__SeqLowBatt__
#define __LIT_Source__SeqLowBatt__

#include "Sequence.h"
#include "CustomElements.h"
#include "LITColor.h"

class SeqLowBatt : public Sequence
{
public:
	SeqLowBatt();
	void update();
	
	int state;
	
	int longWhileCounter;
};



#endif
