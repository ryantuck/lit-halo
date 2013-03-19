//	########################################################################

//  SeqEphemeralSnake.h

//	3/17/13

//	########################################################################

#ifndef __LIT_Source__SeqEphemeralSnake__
#define __LIT_Source__SeqEphemeralSnake__

#include "Sequence.h"
#include "CustomElements.h"
#include "LITColor.h"

class SeqEphemeralSnake : public Sequence
{
public:
	SeqEphemeralSnake();
	SeqEphemeralSnake(Color myColor,
					  int myStart,
					  int myLength,
					  int myRate,
					  int myLayer,
					  bool myDirection);
	
	void update();
	
	int		maxLength;
	bool	direction;
	bool	growing;
};


#endif


