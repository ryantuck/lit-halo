//	########################################################################

//  Pattern0.cpp

//	3/16/13

//	########################################################################

#include "Pattern0.h"

Pattern0::Pattern0()
{
	clearSequences();
	createSequencesArray(1);
	
	sequences[0] = new SeqLowBatt;
}