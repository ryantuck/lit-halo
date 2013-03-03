//	####################################################################

//	MovingDotPattern.cpp

//	####################################################################


#include "MovingDotPattern.h"

MovingDotPattern::MovingDotPattern()
{
	maxSequences = 1;
	sequences = new Sequence*[maxSequences];
	
	sequences[0] = new MovingDotSequence();
}