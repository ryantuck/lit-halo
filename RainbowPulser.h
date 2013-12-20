//
//  RainbowPulser.h
//  litHeadbandSimulator
//
//  Created by Alyssa Lerch on 12/20/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#ifndef __RainbowPulser__
#define __RainbowPulser__

#include "Foo.h"
#include "RainbowLine.h"

class RainbowPulser: public Foo
{
public:
	RainbowPulser();
	
	int counter;
	bool isIncreasing;
	
	void drawNewLine();
};

#endif
