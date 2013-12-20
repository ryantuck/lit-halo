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
	
	Color	white;
	Color	black;
	
	Color	red;
	Color	green;
	Color	blue;
	
	Color	yellow;
	Color	cyan;
	Color	magenta;
	
	
	Color	orange;
	Color	pink;
	Color	lime;
	Color	lavender;
	Color	seaGreen;
	Color	babyBlue;
	
	// arrays
	Color* colorList[8];
	Color* spectrum[12];
	Color* rgb[3];
	Color* cmy[3];
};

extern LITColorClass LITColor;


#endif
