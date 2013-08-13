
#ifndef __ShiftRegister__
#define __ShiftRegister__

#include "Arduino.h"
#include "Color.h"

class ShiftRegister
{
public:
	ShiftRegister();
	
	Color colors[2];
	
	byte led1Addresses[3];
	byte led2Addresses[3];
	
};

#endif
