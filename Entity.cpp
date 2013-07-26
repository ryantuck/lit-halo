//	########################################################################

//  Entity.cpp

//	7/25/13

//	########################################################################

#include "Entity.h"




Entity::Entity()
{
	io			= 1;
	layer		= 1;
	period		= 1;
	readyToDie	= 0;
	brightness	= maxBrightness;
	
}

void Entity::update()
{
	
}

void Entity::updateListOfEntities()
{
	if (entities.length() !=0)
	{
		for (int n=0;n<entities.length();n++)
		{
			entities.entry(n)->me.update();
		}
	}
}

void Entity::updateLEDs()
{
	for (int n=0;n<eLEDs.length();n++)
	{
		int address = eLEDs.entry(n)->me.address;
		
		if (!eLEDs.entry(n)->me.color.isBlack())
		{
			if (layer > leds[address].layer)
			{
				leds[address].setAttributes(eLEDs.entry(n)->me);
				leds[address].layer = layer;
			}
			else if (layer == leds[address].layer)
			{
				eLEDs.entry(n)->me.brightness = brightness;
				leds[address].mixWith(eLEDs.entry(n)->me);
				leds[address].adjustColor();
			}
		}
	}
}

void Entity::setBlock(Color aColor,
					  byte aBrightness,
					  byte aStart,
					  byte aEnd)
{
	// check values
	if (aStart	< 0)			aStart	= 0;
	if (aStart	>= numLEDs)		aStart	= numLEDs;
	if (aEnd	< 0)			aEnd	= 0;
	if (aEnd	>= numLEDs)		aEnd	= numLEDs;
	
	//	update LEDs color and brightness
	if (aStart <= aEnd)						//	doesn't wrap
	{
		for (int n=aStart;n<=aEnd;n++)
		{
			ListObject<AddressedLED>* tmp = new ListObject<AddressedLED>;
			tmp->me.color.setColor(aColor);
			tmp->me.address = n;
			eLEDs.addToEnd(tmp);
			
			brightness = aBrightness;
		}
	}
	else									//	wraps
	{
		for (int n=aStart;n<numLEDs;n++)
		{
			ListObject<AddressedLED>* tmp = new ListObject<AddressedLED>;
			tmp->me.address = n;
			eLEDs.addToEnd(tmp);
		}
		for (int n=0;n<=aEnd;n++)
		{
			ListObject<AddressedLED>* tmp = new ListObject<AddressedLED>;
			tmp->me.address = n;
			eLEDs.addToEnd(tmp);
		}
	}
}

void Entity::checkForUpdate()
{
	periodCounter++;
	
	if (canUpdate())
	{
		update();
		periodCounter = 0;
	}
}

bool Entity::canUpdate()
{
	if (periodCounter == period)	return 1;
	else							return 0;
}







