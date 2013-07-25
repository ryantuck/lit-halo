//	########################################################################

//  Entity.h

//	7/25/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__Entity__
#define __LIT_Headband_Simulator__Entity__


#include "LIT.h"
#include "LinkedList.h"


class Entity
{
public:
	Entity();
	
	LinkedList leds;

	bool io;
	byte layer;
	byte period;
	byte brightness;
	bool readyToDie;
	
	void setBlock(Color aColor,
				  byte aBrightness,
				  byte aStart,
				  byte aEnd);
	
	virtual void update();
	
	void checkForUpdate();
	
	void updateLEDs();
	
	void clear();
	
	void move(bool direction);
	void fade(bool direction);
	
private:
	byte updateValue(byte parameter,
					 bool direction,
					 byte minVal,
					 byte maxVal,
					 bool cycles);
	
	byte periodCounter;
	
	bool canUpdate();
	
	void createLEDsArray(int num);
	
	
};



#endif


