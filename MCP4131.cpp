//	####################################################################
//
//	MCP4131.cpp
//
//	####################################################################

#include "MCP4131.h"

MCP4131::MCP4131()
{
	SPI.begin();
	
	slaveSelectPin = 10;
	
	currentValue = 0;
	pinMode(slaveSelectPin, OUTPUT);
	
}

void MCP4131::update(int newValue)
{
	digitalWrite(slaveSelectPin,LOW);
	
	SPI.transfer(0);
	SPI.transfer(newValue);
	
	digitalWrite(slaveSelectPin,HIGH);
	
	currentValue = newValue;
}
