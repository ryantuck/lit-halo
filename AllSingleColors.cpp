//	########################################################################

//  AllSingleColors.cpp

//	11/24/13

//	########################################################################

#include "AllSingleColors.h"

AllOn::AllOn(Color aColor)
{
	addLEDs(aColor, maxBrightness, 0, 31);
}