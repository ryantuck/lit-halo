//	####################################################################
//
//	Headband.cpp
//
//	####################################################################

#include "Headband.h"

Headband::Headband()
{
	//	initial value for pattern index.

	patternIndex = 2;
	pattern = createPattern(patternIndex);

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
	//	Should also ensure any other steps needed to be taken go in here.
	//		checkBattery().
	
	checkButtons();
	getAudio();
	updateLEDs();
	updateStrip();
}

void Headband::linkUp()
{
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
	
	if (upButton.pressed)
	{
		patternIndex == 10 ? patternIndex = 0 : patternIndex++;
		
		delete pattern;
		pattern = createPattern(patternIndex);
		linkUp();
	}
	
	else if (downButton.pressed)
	{
		patternIndex == 0 ? patternIndex = 10 : patternIndex--;
		
		delete pattern;
		pattern = createPattern(patternIndex);
		linkUp();
	}
}

void Headband::getAudio()
{
	audio.update();
}

Pattern* Headband::createPattern(int index)
{
	switch (index)
	{
		case 0:
			return new MovingDotPattern;
			break;
		case 1:
			return new kernPattern;
			break;
		case 2:
			return new Pattern0;
			break;
		case 3:
			return new Pattern1;
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










