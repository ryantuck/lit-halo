//	####################################################################

//	Sequence.h

//	*	Container for elements.

//	TODO
//	*	test destructor without delete[] operator


//	####################################################################

#ifndef ____Sequence__
#define ____Sequence__

#include "Audio.h"
#include "LED.h"
#include "Element.h"

class Sequence
{
public:
	
	Element**		elements;
	LED*			leds;
	Audio*			audio;
	bool			io;
	byte			numLEDs;
	byte			maxElements;
	
	//	Constructor
	Sequence();
	
	//	Destructor delets all elements
	~Sequence();

	//	Links vitals to elements
	void linkUp();
	
	//	Updates all elements based on defined behavior.
	//	Virtual so custom sequences can define their own behavior.
	//	Default does nothing.
	virtual void update();
	
	//	Returns number of non-null elements.
	//	Relevant for creation/destruction.
	int numElements();
	
	//	Sorts elements so existing elements are first, NULL pointers last.
	void rearrangeElements();
	
	
	//	For testing
	void printVitals();
	
protected:
	void createElementsArray(int number);
};


#endif