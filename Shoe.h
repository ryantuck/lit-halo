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
	Button		button2;
	Button		button1;
    Button      button3;

	Headband();

	void update();
	void updateLEDs();
	void checkButtons();
};


#endif
