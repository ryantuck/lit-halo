//	####################################################################

//	MovingDotPattern.cpp

//	####################################################################


#include "MovingDotPattern.h"

MovingDotPattern::MovingDotPattern()
{
	
	Serial.println("mdp constructor");
	totalSequences = 1;
	sequences = new Sequence*[totalSequences];
	
	sequences[0] = new MovingDotSequence();
}