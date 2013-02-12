//	####################################################################

//	CreationSequence.h

//	*	Tests creation and destruction of elements.
//	*	Shoots a moving dot across the band if beat is detected.

//	####################################################################

#ifndef ____CreationSequence__
#define ____CreationSequence__

#include "Sequence.h"
#include "CustomElements.h"

class CreationSequence : public Sequence
{
public:
	CreationSequence();
	void update();
};



#endif
