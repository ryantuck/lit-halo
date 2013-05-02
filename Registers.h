
#ifndef __Headband__Registers__
#define __Headband__Registers__

#include "ShiftRegister.h"

//#define SHIFTPWM_NOSPI
//const int ShiftPWM_latchPin			= 2;
//const int ShiftPWM_dataPin			= 4;
//const int ShiftPWM_clockPin			= 3;
//const bool ShiftPWM_invertOutputs	= true;
//const bool ShiftPWM_balanceLoad		= false;
//#include "../ShiftPWM/ShiftPWM.h"

class Registers
{
public:
	Registers();
	
	ShiftRegister myRegisters[8];
	
	void setPixelColor(byte address, Color newColor);
	
	void writeRegisters();
	
	void update();
	
private:
	byte latchPin;
	byte clockPin;
	byte dataPin;
};

#endif
