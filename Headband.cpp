//	####################################################################
//
//	Headband.cpp
//
//	####################################################################

#include "Headband.h"

Headband::Headband()
{
	pattern = new kernPattern();
	
	//	Button initialization
	colorButton		= Button(5);
	patternButton	= Button(4);
	
	//	Strip needs initialization bc of non-default constructor.
	strip  = LPD8806(16,2,3);
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
		Color tmpColor;
		
		tmpColor.setColor(leds[n].color);
		
		strip.setPixelColor(n,
							tmpColor.r,
							tmpColor.g,
							tmpColor.b);
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
	
	//	add pattern button functionality
}

void Headband::getAudio()
{
	audio.update();
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










