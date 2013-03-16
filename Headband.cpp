//	####################################################################
//
//	Headband.cpp
//
//	####################################################################

#include "Headband.h"

Headband::Headband()
{
	//	initial value for pattern index.
	
	patternIndex = 3;

	pattern = updatePattern(patternIndex);

	//	Button initialization
	downButton		= Button(5);
	upButton		= Button(4);
	
	//	Strip needs initialization bc of non-default constructor.
	//	DAT - D3
	//	CLK - D2
	strip = LPD8806(16,3,2);
	strip.begin();
}

void Headband::update()
{

	//Serial.println("update Headband");

	checkButtons();
	getAudio();
	updateLEDs();
	updateStrip();
}

void Headband::linkUp()
{
	Serial.println("hbLink up");

	pattern->numLEDs	= sizeof(leds)/sizeof(LED);

	pattern->leds		= leds;
	pattern->audio		= &audio;

	pattern->linkUp();
}

void Headband::updateLEDs()
{
	int numLEDs = sizeof(leds) / sizeof(LED);
	
	for (int n=0;n<numLEDs;n++)
	{
		leds[n].color.setColor(0, 0, 0);
		leds[n].currentLayer = 1;
	}
	
	pattern->update();
}

void Headband::updateStrip()
{
	int numLEDs = sizeof(leds)/sizeof(LED);
	
	for (int n=0;n<numLEDs;n++)
	{
		strip.setPixelColor(n,
							leds[n].color.r,
							leds[n].color.g,
							leds[n].color.b);
	}
	
	strip.show();
}

void Headband::checkButtons()
{
	upButton.checkState();
	downButton.checkState();
	
	if (patternIndex != 0)
	{
		if (upButton.pressed)
		{
			Serial.print("up: ");	Serial.println(patternIndex);
			
			if(patternIndex == 3) patternIndex = 1;
            else patternIndex++;
			
			//delete pattern;
			pattern = updatePattern(patternIndex);
		}
		
		else if (downButton.pressed)
		{
			Serial.print("down: ");	Serial.println(patternIndex);
			
			if(patternIndex == 1)	patternIndex = 3;
            else					patternIndex--;

			//delete pattern;
			pattern = updatePattern(patternIndex);
		}
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

Pattern* Headband::updatePattern(int index)
{
	delete pattern;
	pattern = NULL;
	
	switch (index)
	{
		case 0:
			return new MovingDotPattern;
			linkUp();
			break;
		case 1:
			return new MovingDotPattern;
			linkUp();
			break;
		case 2:
			return new MovingDotPattern;
			linkUp();
			break;
		case 3:
			return new MovingDotPattern;
			linkUp();
			break;
	}
	return NULL;
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










