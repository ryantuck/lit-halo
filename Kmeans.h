//
//  Kmeans.h
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 2/2/14.
//  Copyright (c) 2014 Ryan Tuck. All rights reserved.
//

#ifndef __LIT_Headband_Simulator__Kmeans__
#define __LIT_Headband_Simulator__Kmeans__

#include <vector>
#include "stdlib.h"
using namespace std;
//std library is not compatible w arduino but this code will compile in xcode

#include "LinkedList.h"
#include "Arduino.h"

class Kmeans{
    
private:
    //algo data
    vector<short> points;
    vector<bool> clusters;
    short centroids[2];
    short lastCentroids[2];
    
    //algo params
    short epsilon;
    short numPoints;
    
    //algo output
    short threshold;
    
    //adds new sample to points vector and deletes oldest point
    void addPoint(short point);
    
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
