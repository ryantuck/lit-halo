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
	// equation:
	//	reading = voltage / 0.0048
	
	int maxVoltage = 860;	//	4.25 V
	int minVoltage = 730;	//	3.50 V
	
	float range = maxVoltage - minVoltage;
	float ratio = 100 / range;
	
	Serial.print("ratio: ");
	Serial.println(ratio);
	
	int pct = (voltage() - minVoltage) * ratio;
	
	Serial.print("voltage: ");
	Serial.println(voltage());
	
	return pct;
}

