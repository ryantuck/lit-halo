//	####################################################################

//	LayerTestingSequence.h

//	*	Tests layer functionality.
//	*	Contains 3 elements on differing layers.

//	####################################################################

#ifndef ____LayerTestingSequence__
#define ____LayerTestingSequence__

#include "LITColor.h"
#include "Sequence.h"
#include "CustomElements.h"

class LayerTestingSequence : public Sequence
{
public:
	LayerTestingSequence();
	void update();
};


#endif
