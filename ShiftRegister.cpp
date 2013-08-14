
#include "ShiftRegister.h"

ShiftRegister::ShiftRegister()
{
	led1Addresses[0] = 1;
	led1Addresses[1] = 2;
	led1Addresses[2] = 3;
	
	led2Addresses[0] = 4;
	led2Addresses[1] = 5;
	led2Addresses[2] = 6;
	
	colors[0].setColor(0,0,0);
	colors[1].setColor(0,0,0);
	
}

