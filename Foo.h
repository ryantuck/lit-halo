//	########################################################################

//  Foo.h

//	7/26/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__Foo__
#define __LIT_Headband_Simulator__Foo__

#include "LIT.h"
#include "LinkedList.h"

class Foo
{
public:
	//	Constructor/Destructor ---------
	Foo();
	~Foo();
	
	//	Member Variables ---------------
	Foo**			foos;
	AddressedLED**	fLEDs;
	
	LinkedList<Foo> myFooList;
	LinkedList<LED> myLEDList;
	
	bool	direction;
	bool	io;
	byte	period;
	byte	layer;
	byte	brightness;
	bool	readyToDie;
	
	int		numberOfLEDs;
	int		arrayLength;
	int		numberOfFoos;
	
	byte periodCounter;
	
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
	
	bool canUpdate();
	void switchDirection();
	
	void merge(Foo* aFoo);

	
private:
	byte	updateValue(byte parameter,
						bool direction,
						byte minVal,
						byte maxVal,
						bool cycles);
	
	
	
};



#endif


