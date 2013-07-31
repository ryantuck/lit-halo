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
	//	Constructor/Destructor ---------
	Foo();
	~Foo();
	
	//	Member Variables ---------------
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
	
	//	Foo Array Functionality --------
	void createArray();
	void createArray(int num);
	
	void resizeArray();
	void clearArray();
	void destroyArray();
	
	void addItem();
	void removeItem(int index);
	
	int numItems();
	int lengthOfArray();
	
	//	LED Array Functionality --------
	void setBlock(Color aColor,
				  int aBrightness,
				  int aStart,
				  int aEnd);
	
	void createLEDArray(int num);
	void destroyLEDArray();
	
	//	Updating Functionality ---------
	void iterate();
	void checkForUpdate();
	virtual void update();
	void updateLEDs();
	void updateFoos();
	
	//	Action Functionality -----------
	void move(bool direction);
	
	//	--------------------------------
	void printVitals();
	
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


