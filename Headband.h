//	####################################################################

//	Headband.h

//	*	Acts as over-arching object in code structure.

//	TODO
//	*	add checkBattery() function.

//	####################################################################

#ifndef ____Headband__
#define ____Headband__

#include "LIT.h"
#include "Hardware.h"
#include "Foo.h"
#include "CustomFoos.h"

class Headband
{
public:
	
	Foo*		foo;	
	Battery		batt;
	LPD8806		strip;
	//Registers	lights;
	Button		upButton;
	Button		downButton;
	int			foodex;
	int			maxFoodex;
	
	Headband();
	
	void update();
	void updateLEDs();
	void updateFoo(int index);
	void updateStrip();
	void getAudio();

	void checkButtons();
	void checkBattery();

	void printLEDs();
	
	// in progress
	void updateColors();
	void writeLights();
};


#endif
