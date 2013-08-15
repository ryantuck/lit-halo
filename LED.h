//	####################################################################

//	LED.h

//	*	Contains all relevant information for LEDs.

//	####################################################################

#ifndef ____LED__
#define ____LED__

#include "Color.h"

class LED
{
public:
	
	Color	color;
	byte	brightness;		//	0 - 100
	byte	currentLayer;	//	1 - 127
	
	//	Constructors
	LED();
	LED(Color newColor, byte newBrightness, byte newLayer);
	
	//	For testing
	void printVitals();
};


#endif
