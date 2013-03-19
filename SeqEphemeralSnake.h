//	########################################################################

//  SeqEphemeralSnake.h

//	3/17/13

/*
 
 This sequence is a single element with a single segment that starts at a length of 1, grows to a specified maxLength, and then shrinks back to nothing. Growing is a bool that functionally represents whether it is growing or shrinking. Direction indicates which direction the segment is growing or shrinking. 
 
 */

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


