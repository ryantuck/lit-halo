//	########################################################################

//  Thing.h

//	4/23/13

//	Equivalent of segment + element + sequence

//	########################################################################

#ifndef __Thing__
#define __Thing__

#include "LED.h"
#include "Color.h"

class Thing
{
public:
	
	Thing();
	
	LED leds[16];
	
	byte numLEDs;	// include elsewhere?
	bool io;
	byte layer;
	byte period;
	byte brightness;
	
	void setBlock(Color aColor, byte aBrightness, byte aStart, byte aEnd);
	
	virtual void update();
	
	void move(bool direction);
	void move(bool direction,byte units);
	
	void fade(bool direction);
	void fade(bool direction,byte units);
	
private:
	byte	updateValue(byte parameter,
						bool direction,
						byte minVal,
						byte maxVal,
						bool cycles);
	
};



#endif


