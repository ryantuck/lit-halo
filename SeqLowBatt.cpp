//	########################################################################

//  SeqLowBatt.cpp

//	3/16/13

//	########################################################################


#include "SeqLowBatt.h"

SeqLowBatt::SeqLowBatt()
{
	createElementsArray(1);
	
	elements[0] = new AlternatingElement(LITColor.red,0);
	
	elements[0]->rate = 5;
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
				
				if (longWhileCounter >= 200)
				{
					longWhileCounter = 0;
					state = 0;
				}
				
				break;
		}
	}
	
	elements[0]->update();
}











