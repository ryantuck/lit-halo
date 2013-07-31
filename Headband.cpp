//	####################################################################
//
//	Headband.cpp
//
//	####################################################################

#include "Headband.h"

Headband::Headband()
{
	maxFoodex	= 2;
	foodex		= 0;
	
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
	
	foo->update();
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
		if (foodex == maxFoodex) foodex = 0;
		else foodex++;
		updateFoo(foodex);
	}
	
	else if (downButton.pressed)
	{	
		if (foodex == 0) foodex = maxFoodex;
		else foodex--;
		updateFoo(foodex);
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

void Headband::updateFoo(int index)
{
	delete foo;
	foo = NULL;
	
	switch (index)
	{
		case 0:
			foo = new Foo1;
			break;
		case 1:
			foo = new Foo2;
			break;
		case 2:
			foo = new EventFoo;
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










