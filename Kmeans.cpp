//
//  Kmeans.cpp
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 2/2/14.
//  Copyright (c) 2014 Ryan Tuck. All rights reserved.
//

#include "Kmeans.h"

Kmeans::Kmeans(short numPoints)
{
    centroids[0]		= 0;
    centroids[1]		= 0;
    lastCentroids[0]	= 0;
    lastCentroids[1]	= 0;
	
    numPoints = numPoints;
	epsilon		= 0;
    threshold	= 0;
	
    for (int n = 0; n < numPoints; n++)
    {
		addCluster(false);
        //clusters.push_back(0);
    }
}

Kmeans::Kmeans()
{
    centroids[0]		= 0;
    centroids[1]		= 0;
    lastCentroids[0]	= 0;
    lastCentroids[1]	= 0;
	
    numPoints	= 100;
	epsilon		= 0;
    threshold	= 0;
	
    for (int n = 0; n < numPoints; n++)
    {
		addCluster(false);
        //clusters.push_back(0);
    }
}

void Kmeans::addPoint(byte point)
{
	ListObject<byte>* entry = new ListObject<byte>;
	entry->me = &point;
	
    if(points.length() < numPoints)
    {
		points.addToEnd(entry);
        //points.push_back(point);
    }
    else
    {
		points.removeEntry(0);
		points.addToEnd(entry);
//        points.erase(points.begin());
//        points.push_back(point);
    }
}

void Kmeans::addCluster(bool aVal)
{
	ListObject<bool>* entry = new ListObject<bool>;
	entry->me = &aVal;
	clusters.addToEnd(entry);
}

short Kmeans::update(short point)
{
    addPoint(point);
    if(points.length() == 100)
    {
        initCentroids();
        while(abs(lastCentroids[0] - centroids[0]) > epsilon &&
              abs(lastCentroids[1] - centroids[1]) > epsilon)
        {
            updateDistances();
            updateCentroids();
        }
    }
    threshold = (centroids[0] + centroids[1]) / 2;
    return threshold;
}

void Kmeans::initCentroids()
{
    centroids[0] = *points.entry(rand()%numPoints)->me;
    centroids[1] = 1024;
}


void Kmeans::updateDistances()
{
    for(int n=0; n<numPoints; n++)
    {
		// this math is redundant. should simply check
		// if( centroids[0] > centroids[1] )
        if(*points.entry(n)->me - centroids[0] < *points.entry(n)->me - centroids[1])
        {
            *clusters.entry(n)->me = 0;
        }
        else *clusters.entry(n)->me = 1;
    }
}

void Kmeans::updateCentroids()
{
    byte sum0 = 0; byte sum1 = 0;
    byte cnt0 = 0; byte cnt1 = 0;
    
    for(int n=0;n<numPoints; n++)
    {
        if(*clusters.entry(n)->me == 0)
        {
            sum0 += *points.entry(n)->me;
            cnt0++;
        }
        else
        {
            sum1 += *points.entry(n)->me;
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

void changeNumPoints(short numPoints)
{
    numPoints = numPoints;
}

short Kmeans::getThreshold()
{
    return threshold;
}

