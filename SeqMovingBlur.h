//	########################################################################

//  SeqMovingBlur.h

//	3/16/13

/*
 
 This needs work - doesn't look much like a moving blur. Needs brightness adjustments to allow for brightness gradient to be noticeable.
 
 */

//	########################################################################

#ifndef __LIT_Source__SeqMovingBlur__
#define __LIT_Source__SeqMovingBlur__

#include "Sequence.h"
#include "CustomElements.h"
#include "LITColor.h"

class SeqMovingBlur : public Sequence
{
public:
	SeqMovingBlur();
	SeqMovingBlur(Color blurColor);
	void update();
};



#endif


