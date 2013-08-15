//
//  SeqAltTest.cpp
//  LIT-Source
//
//  Created by Ryan Tuck on 3/13/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "SeqAltTest.h"


SeqAltTest::SeqAltTest()
{
	createElementsArray(1);
	
	elements[0] = new AlternatingElement;
}

void SeqAltTest::update()
{
	Serial.println("sequence update");
	
	elements[0]->update();
}