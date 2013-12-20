//	####################################################################

//	LITColor.cpp

//	####################################################################

#include "LITColor.h"

LITColorClass::LITColorClass()
{
	white.setColor		(1,1,1);
	black.setColor		(0,0,0);
	
	red.setColor		(1,0,0);
	green.setColor		(0,1,0);
	blue.setColor		(0,0,1);
	
	yellow.setColor		(1,1,0);
	cyan.setColor		(0,1,1);
	magenta.setColor	(1,0,1);
	
	orange.setColor		(2,1,0);
	pink.setColor		(2,0,1);
	lime.setColor		(1,2,0);
	lavender.setColor	(1,0,2);
	seaGreen.setColor	(0,2,1);
	babyBlue.setColor	(0,1,2);
	
	
	colorList[0]	= &red;
	colorList[2]	= &green;
	colorList[4]	= &blue;
	colorList[1]	= &yellow;
	colorList[3]	= &cyan;
	colorList[5]	= &magenta;
	colorList[6]	= &white;
	colorList[7]	= &black;
	
	spectrum[0]		= &red;
	spectrum[1]		= &orange;
	spectrum[2]		= &yellow;
	spectrum[3]		= &lime;
	spectrum[4]		= &green;
	spectrum[5]		= &seaGreen;
	spectrum[6]		= &cyan;
	spectrum[7]		= &babyBlue;
	spectrum[8]		= &blue;
	spectrum[9]		= &lavender;
	spectrum[10]	= &magenta;
	spectrum[11]	= &pink;
	
	rgb[0]			= &red;
	rgb[1]			= &green;
	rgb[2]			= &blue;
	
	cmy[0]			= &cyan;
	cmy[1]			= &magenta;
	cmy[2]			= &yellow;
}

LITColorClass LITColor;