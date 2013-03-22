//	########################################################################

//  Pattern3.cpp

//	3/16/13

//	########################################################################

#include "Pattern3.h"


Pattern3::Pattern3()
{
	clearSequences();
	createSequencesArray(1);
	
	sequences[0] = new SeqAltTest;
}
