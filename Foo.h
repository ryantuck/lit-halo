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

	LinkedList<Foo>				foos;
	LinkedList<AddressedLED>	fLEDs;
	
	bool	direction;
	bool	io;
	byte	period;
	byte	layer;
	byte	brightness;
	bool	readyToDie;
	byte	periodCounter;
	
	//	Linked List Shit ---------------
	void addFoo(Foo* aFoo);
	void addLED(AddressedLED* aLED);
	void addFoos(int num);
	void addLEDs(Color aColor, int aBrightness, int aStart, int aEnd);
	
	int	 countFoos();
	int  countLEDs();
	
	bool hasFoos();
	bool hasLEDs();
	
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


