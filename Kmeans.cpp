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
    centroids[0] = 0;
    centroids[1] = 0;
    lastCentroids[0] = 0;
    lastCentroids[1] = 0;
    numPoints = numPoints;
    for (int n = 0; n < numPoints; n++)
    {
        clusters.push_back(0);
    }
    epsilon = 0;
    threshold = 0;

}

Kmeans::Kmeans()
{
    centroids[0] = 0;
    centroids[1] = 0;
    lastCentroids[0] = 0;
    lastCentroids[1] = 0;
    numPoints = 100;
    for (int n = 0; n < numPoints; n++)
    {
        clusters.push_back(0);
    }
    epsilon = 0;
    threshold = 0;
}

void Kmeans::addPoint(short point)
{
    if(points.size() < numPoints)
    {
        points.push_back(point);
    }
    else
    {
        points.erase(points.begin());
        points.push_back(point);
    }
}

short Kmeans::update(short point)
{
    addPoint(point);
    if(points.size() == 100)
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
    centroids[0] = points[rand()%numPoints];
    centroids[1] = 1024;
}


void Kmeans::updateDistances()
{
    for(int n=0; n<numPoints; n++)
    {
        if(points[n] - centroids[0] < points[n] - centroids[1])
        {
            clusters[n] = 0;
        }
        else clusters[n] = 1;
    }
}

void Kmeans::updateCentroids()
{
    short sum0 = 0; short sum1 = 0;
    short cnt0 = 0; short cnt1 = 0;
    
    for(int n=0;n<numPoints; n++)
    {
        if(clusters[n] == 0)
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

void changeNumPoints(short numPoints)
{
    numPoints = numPoints;
}

short Kmeans::getThreshold()
{
    return threshold;
}

