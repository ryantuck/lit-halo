//	####################################################################
//
//	Headband.cpp
//
//	####################################################################

#include "Headband.h"

Headband::Headband()
{
	downButton	= Button(8);
	upButton	= Button(9);
	
	strip = LPD8806(numLEDs,2,3);
	strip.begin();
	
	fooManager = new DevFooManager();
}

void Headband::update()
{
	checkButtons();
	getAudio();
	updateLEDs();
}

void Headband::checkButtons()
{
	//	upButton.checkState();
	//	downButton.checkState();
	
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

}










