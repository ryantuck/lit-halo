//	####################################################################

//	MovingDotSequence.h

//	*	Single moving dot.

//	TODO
//	*	colors must be pre-defined

//	####################################################################

#ifndef ____MovingDotSequence__
#define ____MovingDotSequence__

#include "Sequence.h"
#include "CustomElements.h"
#include "LITColor.h"

class MovingDotSequence : public Sequence
{
public:
	MovingDotSequence();
	void update();
};


#endif
