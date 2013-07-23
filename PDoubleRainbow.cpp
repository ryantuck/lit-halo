//	########################################################################

//  PDoubleRainbow.cpp

//	7/23/13

//	########################################################################

#include "PDoubleRainbow.h"


PDoubleRainbow::PDoubleRainbow()
{
	createThingsArray();
	things[0] = new RainbowThing(0);
	things[1] = new RainbowThing(15);
}

void PDoubleRainbow::update()
{
	genericUpdate();
}

