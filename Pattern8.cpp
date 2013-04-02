//
//  Pattern8.cpp
//  LIT-Source
//
//  Created by Ryan Tuck on 3/22/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "Pattern8.h"

Pattern8::Pattern8()
{
	createSequencesArray(1);
	sequences[0] = new SeqGlitter(LITColor.white, 1);
	//sequences[1] = new SeqGlitter(LITColor.blue, 2);
	//sequences[2] = new SeqGlitter(LITColor.yellow, 3);
	
	linkUp();
}

void Pattern8::update()
{	
	sequences[0]->update();
	//sequences[1]->update();
	//sequences[2]->update();
}