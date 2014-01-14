//
//  Stats.cpp
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 12/3/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "Stats.h"

Stats::Stats(): mean(0),stdev(0), var(0), SNR(0), K(100),
k(0), M(0), S(0)
{}

Stats::Stats(int K): mean(0),stdev(0), var(0), SNR(0), K(K),
                     k(0), M(0), S(0)
{}

void Stats::update(int sample)
{
    //increment sample counter in current iteration
    k++;
    if(k == 1) //if first sample, init algo variables
    {
        M = (double)sample;
        S = 0;
    }
    else if(k >= K) //if sample counter reaches number of samples
    {
        calcStats();
        //printStats();
        clear();
    }
    else
    {
        int M_last = M;
        M = M_last + ((double)sample - M_last)/k;
        S = S + ((double)sample- M_last)*((double)sample - M);
        //Serial.println(S);
        
    }
}


void Stats::calcStats()
{
    var = S/(K-1);
    stdev = sqrt(var);
    mean = M;
}

void Stats::printStats()
{
    Serial.print("var is "); Serial.print(var); Serial.print("  |||  ");
    Serial.print("stdev is "); Serial.print(stdev); Serial.print("  |||  ");
    Serial.print("mean is "); Serial.print(mean);
    Serial.println();
}

void Stats::clear()
{
    k = 0;
    M = 0;
    S = 0;
}

double Stats::getStdev()
{
    return stdev;
}

double Stats::getMean()
{
    return mean;
}

void Stats::setNumSamples(int numSamples)
{
    K = numSamples;
}




