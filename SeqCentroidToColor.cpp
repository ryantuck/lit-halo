//
//  SeqCentroidToColor.cpp
//  LITheadband
//
//  Created by Daniel Kern on 3/15/13.
//  Copyright (c) 2013 Daniel Kern. All rights reserved.
//

#include "SeqCentroidToColor.h"

SeqCentroidToColor::SeqCentroidToColor()
{
    Serial.println("constructor just got called. BAM");
	createElementsArray(1);
	
	elements[0] = new WholeElement;

}

void SeqCentroidToColor::update()
{
    float centroid = audio->eq.centroid();
    int   average = audio->eq.spectrumAvg();
    
    Serial.println(centroid);
    Serial.println(average);
    
    int r,g,b = 0;
    
    if(centroid < 2)
    {
        b = (centroid*127)/2;
        r = 127-b;
    }
    else if(centroid < 4)
    {
        r = (((centroid-2)*127)/2);
        g = 127-r;
    }
    else if(centroid < 6)
    {
        g = (((centroid-4)*127)/2);
        b = 127-g;
    }
    
    
    for(int n = 0; n < elements[0]->numSegments(); n++)
    {
        elements[0]->segments[n]->color.setColor(r,g,b);
        if(average < rand()%1023)
        {
            elements[0]->segments[n]->color.setColor(0,0,0);
        }
    }
    
    elements[0]->update();
    
    
}
