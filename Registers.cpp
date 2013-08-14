

#include "Registers.h"

Registers::Registers()
{
	latchPin	= 2;
	dataPin		= 4;
	clockPin	= 3;
	
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin,OUTPUT);
	pinMode(dataPin, OUTPUT);
	
//	int pwmFrequency = 75;
//	int maxBrightness = 100;
//	ShiftPWM.SetAmountOfRegisters(8);
//	ShiftPWM.SetPinGrouping(1);
//	ShiftPWM.Start(pwmFrequency,maxBrightness);
	
}

void Registers::setPixelColor(byte address, Color newColor)
{
	// check address values for out-of-bounds values
	
	int tmpReg;
	int regAddress = 0;
	
	if (!(address % 2))	tmpReg = address/2;
	else
	{
		address -= 1;
		tmpReg = address/2;
		regAddress = 1;
	}
	
	myRegisters[tmpReg].colors[regAddress].setColor(newColor);
}

void Registers::writeRegisters()
{
	//printLEDs();
	
	digitalWrite(latchPin, 0);
	
	for (int n=7; n>=0; n--)
	{
		// write zero
		digitalWrite(clockPin,	0);
		digitalWrite(dataPin,	1);
		digitalWrite(clockPin,	1);
		
		
		// write led vals
		for (int a=1;a>=0;a--)
		{
			digitalWrite(clockPin, 0);
			digitalWrite(dataPin,!myRegisters[n].colors[a].r);
			digitalWrite(clockPin, 1);
			digitalWrite(clockPin, 0);
			digitalWrite(dataPin,!myRegisters[n].colors[a].g);
			digitalWrite(clockPin, 1);
			digitalWrite(clockPin, 0);
			digitalWrite(dataPin,!myRegisters[n].colors[a].b);
			digitalWrite(clockPin, 1);
		}
		
		// write zero
		digitalWrite(clockPin,	0);
		digitalWrite(dataPin,	1);
		digitalWrite(clockPin,	1);
	}
	
	digitalWrite(latchPin, 1);
}

void Registers::update()
{
	for (int n=0;n<8;n++)
	{
		for (int a=0;a<2;a++)
		{
//			ShiftPWM.SetRGB(n*2+a,
//							myRegisters[n].colors[a].r,
//							myRegisters[n].colors[a].g,
//							myRegisters[n].colors[a].b,
//							n*2+1);
		}
	}
}

void Registers::printLEDs()
{
	Serial.println("LEDs (reg)");
	Serial.println("----");
	for (int n=0;n<8;n++)
	{
		for (int a=0;a<2;a++)
		{
			Serial.print(n*2+a);
			Serial.print(" ");
			if (n*2+a<10) Serial.print(" ");
			myRegisters[n].colors[a].printVitals();
		}
		
	}
}








