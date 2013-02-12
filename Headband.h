//	####################################################################

//	Headband.h

//	*	Acts as over-arching object in code structure.

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
	
	Button		colorButton;
	Button		patternButton;
	
	//	Pattern patternList
	
//	Color		colorList[8];
//	byte		rc	[3];
//	byte		gm	[3];
//	byte		by	[3];
//	byte		rgb	[3];
//	byte		cmy	[3];
//	byte		rgy	[3];
//	byte		gbc	[3];
//	byte		rbm	[3];
//	byte*		colorCombos[8];
//	byte		colorIndex;
//	Color		currentColors[3];
	
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
	
	//	Updates audio object.
	void		getAudio();
	
	//	For testing.
	void		printLEDs();
};


#endif
