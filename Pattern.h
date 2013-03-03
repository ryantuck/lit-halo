//	####################################################################

//	Pattern.h

//	*	Container for sequences.
//	*	Owned by headband.
//	*	Highest level of abstraction in pattern architecture.

//	####################################################################

#ifndef ____Pattern__
#define ____Pattern__

#include "Audio.h"
#include "LED.h"
#include "Sequence.h"
#include "CustomSequences.h"

class Pattern
{
public:
	
	Sequence**		sequences;
	LED*			leds;
	Audio*			audio;
	Color*			colors;
	byte			numLEDs;
	byte			maxSequences;
	
	//	Constructor
	Pattern();
	
	//	Destructor deletes all sequences
	~Pattern();
	
	//	Links vitals with sequences
	void linkUp();
	
	//	Updates sequences
	virtual void update();
	
	//	Returns number of actual sequences
	int	numSequences();
	
	//	[ real sequences ... null pointers ]
	void rearrangeSequences();
	
protected:
	
	void createSegmentsArray(int number);
};

#endif
