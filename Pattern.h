//	####################################################################

//	Pattern.h

//	*	Container for sequences.
//	*	Owned by headband.
//	*	Highest level of abstraction in pattern architecture.

//	TODO
//	*	test destructor without delete[] operator
//	*	what does rearrangeSequences() do? is it used?fg

//	####################################################################

#ifndef ____Pattern__
#define ____Pattern__

#include "Audio.h"
#include "LED.h"
#include "Sequence.h"
#include "CustomSequences.h"
#include "Thing.h"

class Pattern
{
public:
	
	Sequence**		sequences;
	LED*			leds;
	Audio*			audio;
	byte			numLEDs;
	byte			maxSequences;
	
	//	Constructor
	Pattern();
	
	//	Destructor deletes all sequences
	virtual ~Pattern();
	
	//	Links vitals with sequences
	void linkUp();
	
	//	Updates sequences
	virtual void update();
	
	//	Returns number of actual sequences
	int	numSequences();
	
	//	[ real sequences ... null pointers ]
	void rearrangeSequences();
	
protected:
	
	void createSequencesArray(int number);
	void clearSequences();
};

#endif
