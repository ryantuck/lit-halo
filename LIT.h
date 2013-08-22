//	########################################################################

//  LIT.h

//	5/2/13

//	Provides global singletons for access everywhere.

//	########################################################################

#ifndef __Headband__LIT__
#define __Headband__LIT__

#include "LED.h"
#include "Audio.h"
#include "Step.h"

#include "Color.h"
#include "LITColor.h"
#include "Parameters.h"
#include "Arduino.h"
#include "Force.h"

extern int			numLEDs;
extern LayeredLED	leds[32];
extern Audio		audio;

#define up     1
#define down   0
#define cycles 1

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

#endif


