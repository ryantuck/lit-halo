//	####################################################################

//	LITPattern.h

//	*	Container for sequences.
//	*	Owned by headband.
//	*	Highest level of abstraction in LITPattern architecture.

//	TODO
//	*	test destructor without delete[] operator

//	####################################################################

#ifndef ____LITPattern__
#define ____LITPattern__

#include "LIT.h"
#include "Thing.h"

class LITPattern
{
public:
	
	Thing** things;
	
	LITPattern();
	
	virtual ~LITPattern();	// why virtual?

	virtual void update();
	
	void updateLEDs();

	int numThings();
	
protected:
	void createThingsArray();
	void clearThings();
	void genericUpdate();
};

#endif
