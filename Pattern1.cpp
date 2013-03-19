//	########################################################################

//  Pattern1.cpp

//	3/16/13

//	########################################################################


#include "Pattern1.h"


Pattern1::Pattern1()
{
    createSequencesArray(1);
	
	sequences[0] = new SeqCentroidToColor;
}