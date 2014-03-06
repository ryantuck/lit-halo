//
//  Kmeans.h
//  LIT Headband Simulator
//
//  Created by Daniel Kern's butt on 2/2/14.
//  Copyright (c) 2014 Ryan Tuck. All rights reserved.
//

#ifndef __LIT_Headband_Simulator__Kmeans__
#define __LIT_Headband_Simulator__Kmeans__

#define NUM_POINTS 40
#include "Arduino.h"

class Kmeans{
    
private:
    //algo data
	byte points[NUM_POINTS];
	bool clusters[NUM_POINTS];
    byte points_size;
	
    byte centroids[2];
    byte lastCentroids[2];
    
    //algo params
    byte epsilon;
    byte R;
    double lastSumD;
    double sumD;

    
    //algo output
    short threshold;
    
    //adds new sample to points vector and deletes oldest point
    void addPoint(byte point);
    
    //initialize centroids
    void initCentroids();

    //updates the distances from each point to cluster's centroid
    void updateDistances();
    
    //calculates the new centroids for each cluster
    void updateCentroids();
    
    //calculates the sum of the distances from each centroid
    void updateSumDistances();

    
public:
    //constructors
    Kmeans();
    Kmeans(int numPoints);
 
    //runs kmeans algo and calculates new threshold
    byte update(byte point);
    
    //change number of points for which kmeans is calculated on
    void changeNumPoints(int numPoints);
    
    //get threshold
    byte getThreshold();
};

#endif /* defined(__LIT_Headband_Simulator__Kmeans__) */
