//	####################################################################

//	Headband.h

//	========================

//	The over-arching object in the code architecture.
//	Ties together button-checking, fooManager, battery monitoring,
//		and audio functionality.

//	####################################################################

#ifndef __Headband__
#define __Headband__


#include "LIT.h"
#include "LITFunctions.h"
#include "Hardware.h"
#include "FooManager.h"
#include "Foo.h"
#include "CustomFoos.h"

class Headband
{
public:
    
	FooManager*	fooManager;
	Battery		batt;
	Button		upButton;
	Button		downButton;
	
	Button		colorButton;
	Button		patternButton;
	
	int patternIndex; //	should go elsewhere?
		
	//	Constructor
	Headband();

	void update();
	void updateLEDs();
	void getAudio();

	void checkButtons();
	void checkBattery();
};


#endif
