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
};

extern LITColorClass LITColor;


#endif
