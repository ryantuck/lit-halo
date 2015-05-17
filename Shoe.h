//	####################################################################

//	Headband.h

//	========================

//	The over-arching object in the code architecture.
//	Ties together button-checking, fooManager, battery monitoring,
//		and audio functionality.

//	####################################################################

#ifndef __Headband__
#define __Headband__

#include "ShoeConfig.h"
#include "LITFunctions.h"
#include "Hardware.h"
#include "ShoeManager.h"
#include "Foo.h"
#include "CustomFoos.h"

class Shoe
{
public:

	FooManager*	fooManager;
	Button		button2;
	Button		button1;
    Button      button3;

	Shoe();

	void update();
	void updateLEDs();
	void checkButtons();
};


#endif
