//
//  Stats.cpp
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 12/3/13.
//  Copyright (c) 2013 Ryan Tuck. All rights reserved.
//

#include "Stats.h"

Stats::Stats(int K): mean(0),stdev(0), var(0), K(K),
                     k(0), M(0), S(0)
{}

void Stats::update(int sample)
{
    //increment sample counter in current iteration
    k++;
    if(k == 1)
    {
        M = (double)sample;
        S = 0;
        
//        Serial.print("M is ");
//        Serial.println(M);
//        Serial.print("S is ");
//        Serial.println(S);
    }
//    else if(k >= K)
//    {
//        getStats();
//        clear();
//    }
    else
    {
        int M_last = M;
        M = M_last + ((double)sample - M_last)/k;
        S = S + ((double)sample- M_last)*((double)sample - M);
            
//        Serial.print("M is ");
//        Serial.println(M);
//        Serial.print("S is ");
//        Serial.println(S);
    }
}

void Stats::getStats()
{
    var = S/(K-1);
    stdev = sqrt(var);
    mean = M;
//    Serial.print("var is "); Serial.print(var); Serial.print("  |||  ");
//    Serial.print("stdev is "); Serial.print(stdev); Serial.print("  |||  ");
//    Serial.print("mean is "); Serial.print(mean);
//    Serial.println();
}

void Stats::clear()
{
    k = 0;
    M = 0;
    S = 0;
}

void Stats::numSamples(int samples)
{
    K = samples;
}




