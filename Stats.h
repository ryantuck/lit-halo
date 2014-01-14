//
//  Stats.h
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 12/3/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//
//  This class comes 

#ifndef __LIT_Headband_Simulator__Stats__
#define __LIT_Headband_Simulator__Stats__

#include "Arduino.h"
#include <math.h>

class Stats
{
public:
    Stats();
    Stats(int K);
    void update(int sample);
    void setNumSamples(int numSamples);
    
    double getStdev(); //get variance of last sample set
    double getMean(); //get mean of last sample set
    
private:
    //statistics only calculated when k increments to K (number of samples)
    double mean; //average of sample set
    double stdev; //standard deviation
    double var; //variance of sample set
    double SNR; //signal to noise ratio of sample set
    int K; //number of samples
   
    
    //variables for running var algo
    int k; //sample in current iteration
    double M; //
    double S;
    
    void calcStats();
    void printStats(); //print out statistics to serial monitor
    void clear(); //clear variables for running var algo

};

#endif /* defined(__LIT_Headband_Simulator__Stats__) */
