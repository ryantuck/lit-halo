//	####################################################################
//
//	Headband.cpp
//
//	####################################################################

#include "Headband.h"

Headband::Headband()
{
	patternIndex = 0;
	updatePattern(patternIndex);

	downButton		= Button(8);
	upButton		= Button(9);
	
	//	dat-3 / clk-2
	
	// dat and clk currently set for bisco staff
	
	strip = LPD8806(320,2,3);
	strip.begin();
}

void Headband::update()
{
	checkButtons();
	getAudio();
	updateLEDs();
	//updateStrip();
	//writeLights();
}

void Headband::updateLEDs()
{
	for (int n=0;n<numLEDs;n++)
	{
		leds[n].color.setColor(LITColor.black);
		leds[n].layer = 0;
	}
	
	pattern->update();
}

void Headband::updateStrip()
{
	for (int n=0;n<numLEDs;n++)
	{
		strip.setPixelColor(n,
							leds[n].color.r,
							leds[n].color.b,
							leds[n].color.g);
	}
	
	strip.show();
}

void Headband::writeLights()
{
	for (int n=0;n<numLEDs;n++)
		lights.setPixelColor(n, leds[n].color);
	
	lights.writeRegisters();
}

void Headband::checkButtons()
{
	//upButton.checkState();
	//downButton.checkState();
	
	if (upButton.pressed)
	{
		if(patternIndex == 1) patternIndex = 0;
		else patternIndex++;
		
		updatePattern(patternIndex);
	}
	
	else if (downButton.pressed)
	{			
		if(patternIndex == 0) patternIndex = 1;
		else patternIndex--;

		updatePattern(patternIndex);
	}
}

void Headband::checkBattery()
{
//	if (batt.voltage() < 696)
//	{
//		patternIndex = 0;
//		
//		pattern = updatePattern(patternIndex);
//	}
}

void Headband::getAudio()
{
	audio.update();
}

void Headband::updatePattern(int index)
{
	delete pattern;
	pattern = NULL;
	
	switch (index)
	{
		case 0:
			pattern = new PatternA;
			break;
		case 1:
			pattern = new PatternB;
			break;
	}
}


void Headband::printLEDs()
{
	Serial.println("LEDs");
	Serial.println("----");
	for (int n=0;n<16;n++)
	{
		Serial.print(n);
		Serial.print(" ");
		if (n<10) Serial.print(" ");
		leds[n].color.printVitals();
	}
}










