//	########################################################################

//  BatteryFoo.cpp

//	1/7/14

//	########################################################################

#include "BatteryFoo.h"

BatteryFoo::BatteryFoo()
{
	value			= 0;
	valueCounter	= 0;
	repeats			= false;
	
	addStepWithFunction(&BatteryFoo::readAndCalculate, 1, 1);
}

void BatteryFoo::readAndCalculate()
{
	// calculate battery percentage remaining
	int pct = batt.percentage();
	int ledsToTurnOn = pct * 32 / 100;
	value = ledsToTurnOn;

	addStepWithFunction(&BatteryFoo::grow, 1, value);
}

void BatteryFoo::grow()
{
	// set the color of each subsequent LED as some range from red to green
	// this is a bit of a hack, but it works and looks cool.
	// calculateRGB is the same function used to create a rainbow line of
	//	arbitrary length.
	Color tmpColor = Color(LITColor.black);
	tmpColor.calculateRGB(96, valueCounter);
	
	addLEDs(tmpColor, maxBrightness, valueCounter, valueCounter);
	
	valueCounter = updateValue(valueCounter, up, 0, value, !cycles);
}


