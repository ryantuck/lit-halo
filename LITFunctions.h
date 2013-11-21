//	########################################################################

//  LITFunctions.h

//	8/28/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__LITFunctions__
#define __LIT_Headband_Simulator__LITFunctions__

#include "Arduino.h"
#include "Color.h"
#include "LIT.h"

extern byte	updateValue(byte parameter,
						bool direction,
						byte minVal,
						byte maxVal,
						bool doesCycle);

extern byte shortDistance(byte x, byte y);
extern byte longDistance(byte x, byte y);
extern bool shortDirection(byte x, byte y);
extern bool longDirection(byte x, byte y);

extern byte checkAddress(int x);

extern Color SRColor(int index);
extern SRTrio sr3(int index);

extern double runningAverage(double avg,
							 double sample,
							 double numDataPoints);

extern double yOfLine(double m, double b, double x);



#endif


