//	####################################################################

//	Element.h

//	*	Arrangement of segments of LEDs that change state.
//	*	Behavior is defined within custom Sequences.
//	*	Can respond to audio stimulus or can simply move, change layers,
//		increase or decrease rate, turn on or off, or fade brightness. 

//	*	"Primary" objects of pattern architecture.
//	*	Lowest level of abstraction needed for custom objects.


//	####################################################################

#ifndef ____Element__
#define ____Element__

#include "Audio.h"
#include "LED.h"
#include "Segment.h"

class Element
{
public:
	
	Segment**	segments;
	
	byte		layer;
	byte		rate;
	byte		brightness;
	bool		io;
	byte		maxSegments;
	
	byte		rateCounter;
	
	LED*		leds;
	Audio*		audio;
	byte		numLEDs;
	
	//	Constructor
	Element();
	
	//	Destructor deletes all segments.
	~Element();

	//	Returns number of non-null segments.
	//	Relevant if segments are created/destroyed.
	//	If no creation/destruction, numSegments() = maxSegments. 
	int		numSegments	();
	
	//	Updates LEDs with element's data.
	//	Checks layers of leds each segment wants to write to.
	//	If element's layer is higher, overwrites color, brightness.
	//	If layer is same, mixes color/brightness.
	//	Else, does nothing.
	void	updateLEDs	();
	
	//	Update function. Runs each iteration.
	void	update();
	
	//	Updates colors of segments each iteration.
	void updateColors();
	
	//	Change parameters
	void	move		(bool direction);	//	∆ segments starts
	void	fade		(bool direction);	//	∆ brightness
	void	riseFall	(bool direction);	//	∆ layer
	void	accelerate	(bool direction);	//	∆ rate
	void	switchState	();					//	∆ state
	
	//	Checks if element is ready to update.
	//	Ready to update if rateCounter = rate.
	//	If so, updates and resets rateCounter.
	bool	canUpdate	();
	
	
	//	For testing. Prints out essential info.
	void	printVitals	();
	
private:
	
	//	Updates parameter's value.
	//	direction: 0 subtracts, 1 adds
	//	minVal and maxVal set limits on possible values
	//	if cycles = true, then once value hits max, resets at min, and v/v.
	byte	updateValue(byte parameter,
						bool direction,
						byte minVal,
						byte maxVal,
						bool cycles);
protected:
	
	//	Sets maxSegments.
	//	Creates segments[] array.
	//	Creates segments object and makes array point to them.
	void	createSegmentsArray(int number);
};



#endif
