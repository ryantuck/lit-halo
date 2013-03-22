//
//  SeqGlitter.cpp
//  LITheadband
//
//  Created by Daniel Kern on 3/21/13.
//  Copyright (c) 2013 Daniel Kern. All rights reserved.
//

#include "SeqGlitter.h"


SeqGlitter :: SeqGlitter(Color newColor,int layer)
{
    createElementsArray(16);
    
    for(int n = 0; n < 16; n++)
    {
        elements[n] = new DotElement(myColor, n);
        elements[n]->layer = layer;
    }
    
    prob_on = 0;
    counter = 0;
    state   = 0; //prob_on is going up
    
    myColor = newColor;
  
}

void SeqGlitter :: update()
{
    if (prob_on <= 0)   state = 1;
    if (prob_on >= 100) state = 0;
    
    if(state) prob_on++;
    else prob_on--;
    
    for(int n = 0; n < 16; n++)
    {
        if(elements[n]->canUpdate())
        {
            if(prob_on < rand()%100) elements[n]->segments[1]->color.setColor(0,0,0); //rand() expression needs to be revised to return num between 0-100
            else
            {
                elements[n]->segments[1]->color.setColor(myColor);
                elements[n]->brightness = rand()%100;
                
            }
        }
        elements[n]->update();
    }
}
