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
	LPD8806		strip;
	Button		upButton;
	Button		downButton;
	
	Headband();
	
	void update(uint8_t* fht_log_out);
	void updateLEDs();
	void updateStrip();

	void checkButtons();
	void checkBattery();
};


#endif
