//
//  Stats.h
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 12/3/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#ifndef __LIT_Headband_Simulator__Stats__
#define __LIT_Headband_Simulator__Stats__

#include "Arduino.h"
#include <math.h>

class Stats
{
public:
    Stats(int K);
    void update(int sample);
    void numSamples(int samples);
	
	double stdev;
    
    double mean;
    
    double var; //variance of sample set
    int K; //number of samples
   
    
    //variables for running var algo
    int k; //sample in current iteration
    double M; //
    double S;
    
  
    void getStats(); //print out statistics to serial monitor
    void clear(); //clear variables for running var algo
};

#endif /* defined(__LIT_Headband_Simulator__Stats__) */
