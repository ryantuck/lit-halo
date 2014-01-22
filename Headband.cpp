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
	
	fooManager = new ContinuousOutput();
}

void Headband::update()
{
	checkButtons();
	getAudio();
	updateLEDs();
}

void Headband::checkButtons()
{
    upButton.checkState();
    downButton.checkState();
    
	if (upButton.pressed)
	{
        Serial.println("up button pressed by default");
        
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












