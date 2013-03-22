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
	colorList[2] = &green;
	colorList[4] = &blue;
	colorList[1] = &yellow;
	colorList[3] = &cyan;
	colorList[5] = &magenta;
	colorList[6] = &white;
	colorList[7] = &black;
}

LITColorClass LITColor;