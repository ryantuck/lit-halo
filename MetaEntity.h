//	########################################################################

//  MetaEntity.h

//	7/26/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__MetaEntity__
#define __LIT_Headband_Simulator__MetaEntity__

#include "LIT.h"

class MetaEntity
{
public:
	MetaEntity();
	
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

	
	
	
};


#endif


