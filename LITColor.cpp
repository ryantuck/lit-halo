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
	
	rc [0]	= 0;	rc [1]	= 4;	rc [2]	= 7;
	gm [0]	= 1;	gm [1]	= 5;	gm [2]	= 7;
	by [0]	= 2;	by [1]	= 3;	by [2]	= 7;
	rgb[0]	= 0;	rgb[1]	= 1;	rgb[2]	= 2;
	cmy[0]	= 3;	cmy[1]	= 4;	cmy[2]	= 5;
	rgy[0]	= 0;	rgy[1]	= 1;	rgy[2]	= 3;
	gbc[0]	= 1;	gbc[1]	= 2;	gbc[2]	= 4;
	rbm[0]	= 1;	rbm[1]	= 3;	rbm[2]	= 5;
	
	colorCombos[0] = rc;
	colorCombos[1] = gm;
	colorCombos[2] = by;
	colorCombos[3] = rgb;
	colorCombos[4] = cmy;
	colorCombos[5] = rgy;
	colorCombos[6] = gbc;
	colorCombos[7] = rbm;
	
	colorIndex = 4;
}

LITColorClass LITColor;