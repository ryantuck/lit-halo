//	########################################################################

//  AllSingleColors.cpp

//	11/24/13

//	########################################################################

#include "AllSingleColors.h"

AllOn::AllOn(Color aColor, int aBrightness)
{
	addLEDs(aColor, aBrightness, 0, 31);
}