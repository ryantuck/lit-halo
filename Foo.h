//	########################################################################

//  Foo.h

//	7/26/13

//	========================================

//	The generic object containing LEDs, steps for updating, and other foos.

//	########################################################################

#ifndef __Foo__
#define __Foo__

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
	LinkedList<Step<Foo> >		steps;
	
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
	void addStep(Step<T>* aStep)
	{
		// template requires definition in h file
		ListObject<Step<Foo> >* entry = new ListObject<Step<Foo> >;
		entry->me = (Step<Foo>*)aStep;
		steps.addToEnd(entry);
	}
	
	
	
	// ==== current working on this ====================
	template <class T>
	void addStepWithFunction(void (T::*x)(),int aPeriod)
	{
		Step<T>* a = new Step<T>;
		a->fnPtr = x;
		a->period = aPeriod;
		addStep(a);
	}
	// =================================================
	
	
	
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
	void execute(ListObject<Step<Foo> >* obj);
	
	//	Updating Functionality ---------
	void update();
	void updateLEDs();
	void updateFoos();
	void updateSteps();
	
	//	--------------------------------
	void merge(Foo* aFoo);
	
};




#endif


