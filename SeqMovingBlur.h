//	########################################################################

//  SeqMovingBlur.h

//	3/16/13

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


