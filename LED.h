//	####################################################################

//	LED.h

//	Contains LED, LayeredLED, and AddressedLED

//	LED is a container for a color (r,g,b mix) and a brightness.

//	####################################################################

#ifndef __LED__
#define __LED__

#include "Parameters.h"
#include "Color.h"

class LED
{
public:
	
	Color	color;
	byte	brightness;
	
	LED();
	LED(Color newColor, byte newBrightness);

	void adjustColor();
	
	void mixWith(LED aLED);
	
	void setAttributes(LED aLED);
	void setAttributes(Color aColor,byte aBrightness);
	
	//	For testing
	void printVitals();
};


// These two classes were designed for specific use cases.
//	These classes have allowed main LED class to not require holding
//		this data, which saves a ton of space.

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
