//
//  kernSequence.cpp
//  LIT-Source
//
//  Created by Ryan Tuck on 3/2/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "kernSequence.h"

kernSequence::kernSequence()
{
	createElementsArray(4);
	
	elements[0] = new DotElement;
	elements[1] = new DotElement;
	
	elements[0]->segments[0]->color.setColor(LITColor.red);
	elements[1]->segments[0]->color.setColor(LITColor.blue);
	
	elements[0]->rate = 2;
	elements[1]->rate = 3;
	
	elements[2] = new AlternatingElement;
	
	elements[3] = new Element;
	elements[3]->segments[0] = new Segment(LITColor.green,5,3);
}

void kernSequence::update()
{
	if (elements[0]->canUpdate())
	{
		elements[0]->move(0);
	}
	
	if (elements[1]->canUpdate())
	{
		elements[1]->move(1);
	}
	
	if (elements[2]->canUpdate())
	{
		elements[2]->switchState();
	}
	
	if (elements[3]->canUpdate())
	{
		elements[3]->accelerate(1);
		elements[3]->move(1);
	}
	
	for (int n=0;n<maxElements;n++)
	{
		elements[n]->update();
	}
	
	
}