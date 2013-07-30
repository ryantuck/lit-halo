//	########################################################################

//  Foo.h

//	7/26/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__Foo__
#define __LIT_Headband_Simulator__Foo__

#include "LIT.h"

class Foo
{
public:
	Foo();
	~Foo();
	
	Foo**			foos;
	AddressedLED**	fLEDs;
	
	int		buttplug;
	bool	io;
	byte	period;
	byte	layer;
	byte	brightness;
	bool	readyToDie;
	int		numberOfLEDs;
	int		arrayLength;
	int		numberOfFoos;
	
	//	--------------------------------
	void createArray();
	void createArray(int num);
	
	void clearArray();
	void destroyArray();
	void destroyLEDArray();
	void resizeArray();
	
	int numItems();
	int lengthOfArray();
	
	void addItem();
	void removeItem(int index);
	//	--------------------------------
	void createLEDArray(int num);
	
	void setBlock(Color aColor,
				  int aBrightness,
				  int aStart,
				  int aEnd);
	
	void checkForUpdate();
	virtual void update();
	void updateLEDs();
	void updateFoos();
	
	void move(bool direction);
	
private:
	byte	updateValue(byte parameter,
						bool direction,
						byte minVal,
						byte maxVal,
						bool cycles);
	
	byte periodCounter;
	bool canUpdate();
};



#endif


