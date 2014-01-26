//	####################################################################
//
//	Headband.cpp
//
//	####################################################################

#include "Headband.h"

Headband::Headband()
{
	downButton	= Button(5);
	upButton	= Button(6);
	
	strip = LPD8806(numLEDs,2,3);
	strip.begin();
	
    //set foo manager here. a foo manager will determine which
    //set of patterns are available to run on the headband
	fooManager = new BandFooManager();
	fooManager->update();
}

void Headband::update()
{
	checkButtons();
//	checkBattery();
	getAudio();
	updateLEDs();
    //audio.printSpectrum();
}

void Headband::checkButtons()
{
	upButton.checkState();
	downButton.checkState();
	
	if (upButton.pressed)
	{
		fooManager->foodex = updateValue(fooManager->foodex,
										up,
										0,
										fooManager->maxFoodex,
										cycles);
		fooManager->update();
	}
	else if (downButton.pressed)
	{
		fooManager->foodex = updateValue(fooManager->foodex,
										down,
										0,
										fooManager->maxFoodex,
										cycles);
		fooManager->update();
	}
	
}

void Headband::getAudio()
{
	audio.update();
}

void Headband::updateLEDs()
{
	for (int n=0;n<numLEDs;n++)
	{
		leds[n].color.setColor(LITColor.black);
		leds[n].layer = 0;
	}

	fooManager->foo->update();
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

//	================================================================

void Headband::checkBattery()
{
	// read battery voltage and 3V line
	int v = batt.voltage();
	int t = analogRead(7); // this checks 3V line
	
	// based on empirical relationship, determine batt percentage
	
	// based on batt percentage, do something.
	//  possibly shut off if too low? 
}










