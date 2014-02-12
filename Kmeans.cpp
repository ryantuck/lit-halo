//
//  Kmeans.cpp
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 2/2/14.
//  Copyright (c) 2014 Ryan Tuck. All rights reserved.
//

#include "Kmeans.h"

Kmeans::Kmeans()
{
    centroids[0]		= 0;
    centroids[1]		= 0;
    lastCentroids[0]	= 0;
    lastCentroids[1]	= 0;
	
	epsilon		= 2;
    threshold	= 0;
    
    points_size = 0;
}

void Kmeans::addPoint(byte point)
{
    
    if(points_size < NUM_POINTS) points_size++;
    
    for(int i = points_size-1; i >= 1; i--)
    {
        points[i] = points[i-1];
    }
 
    points[0] = point;
}

byte Kmeans::update(byte point)
{
    addPoint(point);
    if(points_size == NUM_POINTS)
    {
        initCentroids();
        while(abs(lastCentroids[0] - centroids[0]) < epsilon &&
              abs(lastCentroids[1] - centroids[1]) < epsilon)
        {
            updateDistances();
            updateCentroids();
        }
    }
    threshold = (centroids[0] + centroids[1]) / 2;
	
	Serial.print("thresh: ");
	Serial.println(threshold);
	
    return threshold;
}

void Kmeans::initCentroids()
{
    centroids[0] = points[rand()%NUM_POINTS];
    centroids[1] = points[rand()%NUM_POINTS];
}


void Kmeans::updateDistances()
{
    for(int n=0; n<NUM_POINTS; n++)
    {
        if(abs(points[n] - centroids[0]) < abs(points[n] - centroids[1]))
        {
            clusters[n] = false;
        }
        else clusters[n] = true;
    }
}

void Kmeans::updateCentroids()
{
    byte sum0 = 0; byte sum1 = 0;
    byte cnt0 = 0; byte cnt1 = 0;
    
    for(int n=0;n<NUM_POINTS; n++)
    {
        if(clusters[n] == false)
        {
            sum0 += points[n];
            cnt0++;
        }
        else
        {
            sum1 += points[n];
            cnt1++;
        }
    }
    
    if(cnt0 == 0) cnt0 = 1;
    if(cnt1 == 0) cnt1 = 1;
    
    lastCentroids[0] = centroids[0];
    lastCentroids[1] = centroids[1];
    
    centroids[0] = sum0/cnt0;
    centroids[1] = sum1/cnt1;
}

byte Kmeans::getThreshold()
{
    return threshold;
}

