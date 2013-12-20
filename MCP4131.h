//	####################################################################
//
//	MCP4131.h
//
//	####################################################################

#ifndef ____MCP4131__
#define ____MCP4131__

#include "Arduino.h"
#include "SPI.h"


class MCP4131
{
private:
	
	int slaveSelectPin;
	
public:
	
	//	Constructor
	MCP4131();
	
	//	Current pot value.
	byte currentValue;
	
	//	Writes new value to pot.
	void update(int newValue);
};

#endif
