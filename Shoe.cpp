//	####################################################################
//
//	Headband.cpp
//
//	####################################################################

#include "Headband.h"

Headband::Headband()
{
	button1	= Button(5);
	button2	= Button(6);
    button3 = Button(7);

	fooManager = new MasterFooManager();
}

void Headband::update()
{
	checkButtons();
	audio.update();
	updateLEDs();
}

void Headband::checkButtons()
{
	bool hardware = true;
	if (hardware)
	{
		button1.checkState();
		button2.checkState();
        button3.checkState();
	}

	if (button1.pressed)
	{
		fooManager->foodex = updateValue(fooManager->foodex,
										up,
										0,
										fooManager->maxFoodex,
										cycles);
		fooManager->update();
	}
	else if (button2.pressed)
	{
		fooManager->foodex = updateValue(fooManager->foodex,
										down,
										0,
										fooManager->maxFoodex,
										cycles);
		fooManager->update();
	}
    else if (button3.pressed)
    {
        fooManager->foodex = updateValue(fooManager->foodex,
                                        down,
                                        0,
                                        fooManager->maxFoodex,
                                        cycles);
    }

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












