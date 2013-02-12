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
	int maxVoltage = 750;
	int minVoltage = 0;
	
	return maxVoltage - minVoltage;
}