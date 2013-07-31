//	####################################################################

//	LED.h

//	Contains LED, LayeredLED, and AddressedLED

//	####################################################################

#ifndef ____LED__
#define ____LED__

#include "Parameters.h"
#include "Color.h"

class LED
{
public:
	
	Color	color;
	byte	brightness;
	
	//	Constructors
	LED();
	LED(Color newColor, byte newBrightness);
	
	//	Adjusts color based on LED brightness.
	void adjustColor();
	
	void mixWith(LED aLED);
	
	void setAttributes(LED aLED);
	void setAttributes(Color aColor,byte aBrightness);
	
	//	For testing
	void printVitals();
};



class AddressedLED : public LED
{
public:
	AddressedLED();
	AddressedLED(byte a);
	byte address;
};

class LayeredLED : public LED
{
public:
	LayeredLED();
	LayeredLED(byte l);
	byte layer;
};


#endif
