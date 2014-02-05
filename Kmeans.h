//
//  Kmeans.h
//  LIT Headband Simulator
//
//  Created by Daniel Kern's butt on 2/2/14.
//  Copyright (c) 2014 Ryan Tuck. All rights reserved.
//

#ifndef __LIT_Headband_Simulator__Kmeans__
#define __LIT_Headband_Simulator__Kmeans__

#include "LinkedList.h"
#include "Arduino.h"

class Kmeans{
    
private:
    //algo data
	LinkedList<byte> points;
	LinkedList<bool> clusters;
	
    byte centroids[2];
    byte lastCentroids[2];
    
    //algo params
    short epsilon;
    short numPoints;
    
    //algo output
    short threshold;
    
    //adds new sample to points vector and deletes oldest point
    void addPoint(byte point);
	
	// just adds a cluster
	void addCluster(bool aVal);
    
    //initialize centroids
    void initCentroids();

    //updates the distances from each point to cluster's centroid
    void updateDistances();
    
    //calculates the new centroids for each cluster
    void updateCentroids();
    
public:
    //constructors
    Kmeans();
    Kmeans(short numPoints);
 
    //runs kmeans algo and calculates new threshold
    short update(short point);
    
    //change number of points for which kmeans is calculated on
    void changeNumPoints(short numPoints);
    
    //get threshold
    short getThreshold();
};

#endif /* defined(__LIT_Headband_Simulator__Kmeans__) */
