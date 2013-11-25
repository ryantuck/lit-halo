//	####################################################################

//	Headband.h

//	####################################################################

#ifndef ____Headband__
#define ____Headband__

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
	
	Headband();
	
	void update();
	void updateLEDs();
	void getAudio();

	void checkButtons();
	void checkBattery();
};


#endif
