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
	LinkedList<Step<Foo>>		steps;
	
	byte	period;
	byte	periodCounter;
	bool	direction;
	bool	io;
	bool	readyToDie;
	
	byte	layer;
	byte	brightness;
	
	int currentStep;
	bool isRecurring;
	bool isRunning;
	
	//	Linked List Shit ---------------
	void addFoo(Foo* aFoo);
	void addLED(AddressedLED* aLED);
	void addFoos(int num);
	void addLEDs(Color aColor, int aBrightness, int aStart, int aEnd);
	
	int	 countFoos();
	int  countLEDs();
	int  countSteps();
	
	bool hasFoos();
	bool hasLEDs();
	bool hasSteps();
	
	void checkSteps();
	void resetSteps();
	
	void execute(ListObject<Step<Foo>>* obj);
	
	void updateSteps();
	
	template <class T>
	void addStep(Step<T>* aStep);
	
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
	
	void printTest();
	
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


