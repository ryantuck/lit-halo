//	########################################################################

//  PEventTester.h

//	7/23/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__PEventTester__
#define __LIT_Headband_Simulator__PEventTester__

#include "Pattern.h"
#include "CustomThings.h"

class PEventTester : public LITPattern
{
public:
	PEventTester();
	
	int addCounter;
	int colorIndex;
	
	void update();
};



#endif


