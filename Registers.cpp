

#include "Registers.h"

Registers::Registers()
{
	latchPin	= 2;
	dataPin		= 3;
	clockPin	= 4;
}

void Registers::setPixelColor(byte address, Color newColor)
{
	// check address values for out-of-bounds values
	
	int tmpReg;
	int regAddress = 0;
	
	if (address % 2)	tmpReg = address/2;
	else
	{
		tmpReg = address/2 - 0.5;
		regAddress = 1;
	}
	
	myRegisters[address].colors[regAddress].setColor(newColor);
}

void Registers::writeRegisters()
{
	digitalWrite(latchPin, 0);
	
	for (int n=8; n>0; n--)
	{
		// write zero
		digitalWrite(clockPin,	0);
		digitalWrite(dataPin,	1);
		digitalWrite(clockPin,	1);
		
		
		// write led vals
		for (int a=1;a>=0;a--)
		{
			digitalWrite(clockPin, 0);
			digitalWrite(dataPin,!myRegisters[n].colors[a].b);
			digitalWrite(clockPin, 1);
			digitalWrite(clockPin, 0);
			digitalWrite(dataPin,!myRegisters[n].colors[a].g);
			digitalWrite(clockPin, 1);
			digitalWrite(clockPin, 0);
			digitalWrite(dataPin,!myRegisters[n].colors[a].r);
			digitalWrite(clockPin, 1);
		}
		
		// write zero
		digitalWrite(clockPin,	0);
		digitalWrite(dataPin,	1);
		digitalWrite(clockPin,	1);
	}
	
	digitalWrite(latchPin, 1);
}


