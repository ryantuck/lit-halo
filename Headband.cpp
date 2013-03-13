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
	colorButton		= Button(5);
	patternButton	= Button(4);
	
	//	Strip needs initialization bc of non-default constructor.
	//	DAT - D3
	//	CLK - D2
	strip = LPD8806(16,3,2);
	strip.begin();
}

void Headband::update()
{
	checkButtons();
	getAudio();
	updateColors();
	updateLEDs();
	updateStrip();	
}

void Headband::linkUp()
{
	pattern->numLEDs	= sizeof(leds)/sizeof(LED);
	pattern->leds		= leds;
	pattern->audio		= &audio;
	pattern->colors		= LITColor.currentColors;
	
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

void Headband::updateColors()
{	
	for (int n=0;n<3;n++)
		LITColor.currentColors[n] = *LITColor.colorList[LITColor.colorCombos[LITColor.colorIndex][n]];
}

void Headband::updateStrip()
{
	int numLEDs = sizeof(leds)/sizeof(LED);
	
	for (int n=0;n<numLEDs;n++)
	{
		//	adjust r,g,b values based on led brightness and write to strip.
		
		float ratio = leds[n].brightness / 100;
		
		int tmpR = leds[n].color.r * ratio;
		int tmpG = leds[n].color.g * ratio;
		int tmpB = leds[n].color.b * ratio;
		
		strip.setPixelColor(n,
							tmpR,
							tmpG,
							tmpB);
	}
	
	strip.show();
}

void Headband::checkButtons()
{
	colorButton.checkState();
	if (colorButton.pressed)
	{
		Serial.println("pressed");
		if (LITColor.colorIndex == 7)	LITColor.colorIndex = 0;
		else							LITColor.colorIndex++;
	}
	
	patternButton.checkState();
	if (patternButton.pressed)
	{
		Serial.println("pressed");
		delete pattern;
		pattern = NULL;
		pattern = createPattern(patternIndex);
		if (patternIndex == 10)		patternIndex = 0;
		else						patternIndex++;
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










