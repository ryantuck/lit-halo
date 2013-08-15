//	####################################################################
//
//	Battery.cpp
//
//	####################################################################


#include "Battery.h"

Battery::Battery()
{
	pin = 1;
}

void Battery::readVoltage()
{
	voltage = analogRead(pin);
}

int Battery::percentage()
{
	int maxVoltage = 860;		//	4.2 V ?
	int minVoltage = 675;		//	3.3 V ?
	
	float ratio = 100 / (maxVoltage - minVoltage);
	
	int pct = (voltage - minVoltage) * ratio;
	
	return pct;
}

