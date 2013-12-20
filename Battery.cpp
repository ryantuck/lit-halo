//	####################################################################
//
//	Battery.cpp
//
//	####################################################################


#include "Battery.h"

Battery::Battery()
{
	pin = 0;
}

int Battery::voltage()
{
	return analogRead(pin);
}

int Battery::percentage()
{
	int maxVoltage = 860;		//	4.2 V ?
	int minVoltage = 696;		//	3.397385391181 V ?
	
	float ratio = 100 / (maxVoltage - minVoltage);
	
	int pct = (voltage() - minVoltage) * ratio;
	
	return pct;
}

