//
//  Kmeans.cpp
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 2/2/14.
//  Copyright (c) 2014 Ryan Tuck. All rights reserved.
//

#include "Kmeans.h"

Kmeans::Kmeans(int numPoints)
{
    centroids[0]		= 0;
    centroids[1]		= 0;
    lastCentroids[0]	= 0;
    lastCentroids[1]	= 0;
	
    numPoints = numPoints;
	epsilon		= 2;
    threshold	= 0;
	
    for (int n = 0; n < numPoints; n++)
    {
		clusters.add(false);
    }
}

Kmeans::Kmeans()
{
    centroids[0]		= 0;
    centroids[1]		= 0;
    lastCentroids[0]	= 0;
    lastCentroids[1]	= 0;
	
    numPoints	= 10;
	epsilon		= 2;
    threshold	= 0;
	
    for (int n = 0; n < numPoints; n++)
    {
		clusters.add(false);
    }
}

void Kmeans::addPoint(byte point)
{
    if(points.size() < numPoints)
    {
		points.add(point);
    }
    else
    {
		points.shift();
		points.add(point);
	}
}

byte Kmeans::update(byte point)
{
    addPoint(point);
    if(points.size() == numPoints)
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
    centroids[0] = points.get(rand()%numPoints);
    centroids[1] = 1024;
}


void Kmeans::updateDistances()
{
    for(int n=0; n<numPoints; n++)
    {
        if(abs(points.get(n) - centroids[0]) < abs(points.get(n) - centroids[1]))
        {
            clusters.set(n, false);
        }
        else clusters.set(n, true);
    }
}

void Kmeans::updateCentroids()
{
    byte sum0 = 0; byte sum1 = 0;
    byte cnt0 = 0; byte cnt1 = 0;
    
    for(int n=0;n<numPoints; n++)
    {
        if(clusters.get(n) == 0)
        {
            sum0 += points.get(n);
            cnt0++;
        }
        else
        {
            sum1 += points.get(n);
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

void changeNumPoints(int numPoints)
{
    numPoints = numPoints;
}

byte Kmeans::getThreshold()
{
    return threshold;
}

