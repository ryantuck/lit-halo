//	####################################################################

//	LITColor.h

//	*	Holds LIT-specific colors and color lists for hb use.

//	####################################################################

#ifndef ____LITColor__
#define ____LITColor__

#include "Color.h"

class LITColorClass
{
public:
	LITColorClass();
	
	Color	red;
	Color	green;
	Color	blue;
	Color	yellow;
	Color	cyan;
	Color	magenta;
	Color	white;
	Color	black;
	
	Color*	colorList[8];
	
	byte	rc	[3];		//	complements
	byte	gm	[3];
	byte	by	[3];
	byte	rgb	[3];		//	triples
	byte	cmy	[3];
	byte	rgy	[3];		//	2 primaries + mix
	byte	gbc	[3];
	byte	rbm	[3];
	byte*	colorCombos[8];
	byte	colorIndex;
	Color	currentColors[3];
	
};

extern LITColorClass LITColor;


#endif
