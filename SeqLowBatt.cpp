//
//  SeqLowBatt.cpp
//  LIT-Source
//
//  Created by Ryan Tuck on 3/13/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "SeqLowBatt.h"

SeqLowBatt::SeqLowBatt()
{
	createElementsArray(1);
	
	Color myColor(20,30,10);
	
	elements[0] = new AlternatingElement(myColor,0);
	
	elements[0]->rate = 3;
	elements[0]->brightness = 0;
	
	
	state = 0;
	
	longWhileCounter = 0;
	
}

void SeqLowBatt::update()
{
	if (elements[0]->canUpdate())
	{
		switch (state)
		{
			case 0:
				
                elements[0]->io = 1;
				elements[0]->fade(1);
				
				if (elements[0]->brightness >= 100) state = 1;
				break;
				
			case 1:
				
				elements[0]->fade(0);
				if (elements[0]->brightness <= 0)
                {
                    state = 2;
                }
				
				break;
				
			case 2:
                
                elements[0]->io = 0;
				longWhileCounter++;
				
				if (longWhileCounter >= 1000)
				{
					longWhileCounter = 0;
					state = 0;
				}
				
				break;
		}
	}
	
	elements[0]->update();
}











