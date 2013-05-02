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
//#include "Sequence.h"
//#include "CustomSequences.h"
#include "Thing.h"

class Pattern
{
public:
	
	Thing** things;
	
	Pattern();
	
	virtual ~Pattern();			// why virtual?

	virtual void update();
	
	void updateLEDs();

	int numThings();
	
protected:
	void createThingsArray();
	void clearThings();
};

#endif
