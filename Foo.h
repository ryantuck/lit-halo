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
	
	byte		layer;
	byte		brightness;
	
	int			stepIndex;
	bool		repeats;
	
	bool		isRunning;
	
	Step<Foo>*	theCurrentStep;
	
	//	Adding -------------------------
	void addFoo(Foo* aFoo);
	void addFoos(int num);
	
	void addLED(AddressedLED* aLED);
	void addLEDs(Color aColor, int aBrightness, int aStart, int aEnd);
	
	template <class T>
	void addStep(Step<T>* aStep);
	
	//	Counting -----------------------
	int	 countFoos();
	int  countLEDs();
	int  countSteps();
	
	bool hasFoos();
	bool hasLEDs();
	bool hasSteps();
	
	//	Step Stuff ---------------------
	void checkSteps();
	void resetSteps();
	void execute(ListObject<Step<Foo>>* obj);
	
	//	Updating Functionality ---------
	void update();
	void updateLEDs();
	void updateFoos();
	void updateSteps();
	
	//	Action Functionality -----------
	void move(bool direction);
	
	//	--------------------------------
	void printVitals();
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


