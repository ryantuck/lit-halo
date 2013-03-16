//	####################################################################

//	Headband.h

//	*	Acts as over-arching object in code structure.

//	TODO
//	*	add checkBattery() function.
//	*	remove updateColors() function.
//	*	clean up createPattern().

//	####################################################################

#ifndef ____Headband__
#define ____Headband__

#include "Audio.h"
#include "LED.h"
#include "Pattern.h"
#include "Hardware.h"
#include "LITColor.h"
#include "CustomPatterns.h"

class Headband
{
public:
	
	Pattern*	pattern;
	Audio		audio;
	LED			leds[16];
	
	Battery		batt;
	
	LPD8806		strip;
	
	Button		upButton;
	Button		downButton;
	
	int patternIndex;				//	should go elsewhere?
		
	
	//	Constructor
	Headband();
	
	//	Links pattern with vitals
	void		linkUp();
	
	//	Runs each iteration. Updates everything.
	void		update();
	
	//	Updates Pattern, etc, which updates LEDs.
	void		updateLEDs();
	
	//	Changes current colors.
	void		updateColors();
	
	//	Writes LED data to LPD8806.
	void		updateStrip();
	
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
