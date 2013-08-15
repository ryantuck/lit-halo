//	####################################################################
//
//	Battery.h
//
//	####################################################################


#ifndef ____Battery__
#define ____Battery__

#include "Arduino.h"

class Battery
{
public:
	Battery();
	int voltage;
	
	void readVoltage();
	int  percentage();
	
private:
	byte pin;
};

#endif
