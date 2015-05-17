//	####################################################################
//
//	Headband.cpp
//
//	####################################################################

#include "Shoe.h"

Shoe::Shoe()
{
	button1	= Button(5);
	button2	= Button(6);
    button3 = Button(7);

	fooManager = new ChroFooManager();
}

void Shoe::update()
{
	checkButtons();
	audio.update();
	updateLEDs();
}

void Shoe::checkButtons()
{
    bool hardware = false;
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

void Shoe::updateLEDs()
{
	for (int n=0;n<numLEDs;n++)
	{
		leds[n].color.setColor(LITColor.black);
		leds[n].layer = 0;
	}

	fooManager->foo->update();
}












