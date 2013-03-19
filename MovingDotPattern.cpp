//	####################################################################

//	MovingDotPattern.cpp

//	####################################################################


#include "MovingDotPattern.h"

MovingDotPattern::MovingDotPattern()
{
	createSequencesArray(1);
	
	sequences[0] = new SeqMovingDot();
}