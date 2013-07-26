//	########################################################################

//  EntityTestThing.cpp

//	7/26/13

//	########################################################################

#include "EntityTestThing.h"


EntityTestThing::EntityTestThing()
{
	clear();
}

void EntityTestThing::update()
{
	for (int n=0;n<myEnt.eLEDs.length();n++)
	{
		int address = myEnt.eLEDs.entry(n)->me.address;
		
		tLEDs[address].brightness = brightness;
		tLEDs[address].color.setColor(myEnt.eLEDs.entry(n)->me.color);
	}
	
	for (int l=0;l<myEnt.entities.length();l++)
	{
//		for (int n=0;n<myEnt.entities.entry(l)->me.eLEDs.length();n++)
//		{
//			
//		}
	}
}




