//	####################################################################

//	MovingDotSequence.h

//	*	Single moving dot.

//	*	Should probably have constructor that can define direction of movement.

//	####################################################################

#ifndef ____MovingDotSequence__
#define ____MovingDotSequence__

#include "Sequence.h"
#include "CustomElements.h"
#include "LITColor.h"

class SeqMovingDot : public Sequence
{
public:
	SeqMovingDot();
	SeqMovingDot(Color myColor, int myStart);
	void update();
};


#endif
