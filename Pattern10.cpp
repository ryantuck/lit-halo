//
//  Pattern10.cpp
//  LITheadband
//
//  Created by Daniel Kern on 3/21/13.
//  Copyright (c) 2013 Daniel Kern. All rights reserved.
//

#include "Pattern10.h"


Pattern10::Pattern10()
{
	createSequencesArray(4);
	
	sequences[0] = new SeqGlitter(LITColor.white, 1);
}

void Pattern10 :: update()
{
    switch (state)
    {
        case 0:
            //pick a random time to wait between 1 and 10 seconds
            randomTime = rand()%9000 + 1000; //between 1000 and 10000
            previousTime = millis();
            state = 1;
            break;
        case 1:
            //check if the random time has elapsed
            //if random time has elapsed move to next state
            if(millis() - previousTime > randomTime) state = 2;
            break;
        case 2:
            //with probabiliy 50%, destroy sequences
            for(int n = 0; n < numSequences(); n++)
            {
                if(rand()%2 == 1)
            }
                
            //add new SeqGlitter sequence using random color and random layer
                
            //move to next state
            break;
    }
    
    //update sequences;
    for(int n = 0; n < numSequences(); n++)
    {
        sequences[n]->update();
    }
}
