//	########################################################################

//  Pattern2.cpp

//	3/16/13

//	########################################################################


#include "Pattern2.h"


Pattern2::Pattern2()
{
	clearSequences();
	createSequencesArray(1);
	
	sequences[0] = new SeqMovingBlur(LITColor.magenta);
}