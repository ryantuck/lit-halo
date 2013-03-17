//	####################################################################

//	LITColor.cpp

//	####################################################################

#include "LITColor.h"

LITColorClass::LITColorClass()
{
	red.setColor	(1,0,0);
	green.setColor	(0,1,0);
	blue.setColor	(0,0,1);
	yellow.setColor	(1,1,0);
	cyan.setColor	(0,1,1);
	magenta.setColor(1,0,1);
	white.setColor	(1,1,1);
	black.setColor	(0,0,0);
	
	colorList[0] = &red;
	colorList[1] = &green;
	colorList[2] = &blue;
	colorList[3] = &yellow;
	colorList[4] = &cyan;
	colorList[5] = &magenta;
	colorList[6] = &white;
	colorList[7] = &black;
}

LITColorClass LITColor;