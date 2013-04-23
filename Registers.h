
#ifndef __Headband__Registers__
#define __Headband__Registers__

#include "ShiftRegister.h"

class Registers
{
public:
	Registers();
	
	ShiftRegister myRegisters[8];
	
	void setPixelColor(byte address, Color newColor);
	
	void writeRegisters();
	
private:
	byte latchPin;
	byte clockPin;
	byte dataPin;
};

#endif
