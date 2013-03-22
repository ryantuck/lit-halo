//	########################################################################

//  Pattern6.cpp

//	3/18/13

//	########################################################################

#include "Pattern6.h"


Pattern6::Pattern6()
{
	clearSequences();
	createSequencesArray(1);
	
	sequences[0] = new SeqRainbowSnake;
}
