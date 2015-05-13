//	########################################################################

//  LIT.h

//	5/2/13

//	Provides global singletons for access everywhere.

//	########################################################################

#ifndef __Headband__LIT__
#define __Headband__LIT__

#include "LED.h"
#include "Step.h"

#include "Color.h"
#include "LITColor.h"
#include "Parameters.h"
#include "Arduino.h"
#include "Force.h"

#include "LinkedList.h"

extern int			numLEDs;
extern LayeredLED	leds[12];

#define up     1
#define down   0
#define cycles 1

#endif


