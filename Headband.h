//	####################################################################

//	Headband.h

//	*	Acts as over-arching object in code structure.

//	TODO
//	*	add checkBattery() function.

//	####################################################################

#ifndef ____Headband__
#define ____Headband__

#include "LIT.h"
#include "Pattern.h"
#include "CustomPatterns.h"
#include "Hardware.h"


class Headband
{
public:
	
	LITPattern*	pattern;
	
	Battery		batt;
	
	LPD8806		strip;
	
	Registers	lights;
	
	Button		upButton;
	Button		downButton;
	
	int patternIndex;				//	should go elsewhere?
	int maxIndex;
		
	
	//	Constructor
	Headband();
	
	//	Runs each iteration. Updates everything.
	void		update();
	
	//	Updates Pattern, etc, which updates LEDs.
	void		updateLEDs();
	
	//	Changes current colors.
	void		updateColors();
	
	//	Writes LED data to LPD8806.
	void		updateStrip();
	
	void writeLights();
	
	//	Checks buttons for presses and updates counters accordingly.
	void		checkButtons();
	
	//	Checks battery.
	void		checkBattery();
	
	//	Updates audio object.
	void		getAudio();
	
	//	Creates new instance of pattern object.
	void updatePattern(int index);
	
	//	For testing.
	void		printLEDs();
};


#endif
