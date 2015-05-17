//	########################################################################

//  FooManager.h

//	8/21/13

//	########################################################################

#ifndef __FooManager__
#define __FooManager__

#include "Foo.h"
#include "CustomFoos.h"

class FooManager
{
public:
	FooManager();
	
	Foo* foo;
	int foodex;
	int maxFoodex;
	
	void update();
	void updateFoo(int index);
	virtual void createNewFoo(int index);
};

class ChroFooManager : public FooManager
{
public:
    ChroFooManager();
    void createNewFoo(int index);
};

//  ================================================================
//	Master
//	The best non-buggy foos we have.
//  ================================================================
class MasterFooManager : public FooManager
{
public:
	MasterFooManager();
	void createNewFoo(int index);
};

//  ================================================================
//	Dev
//	Stuff that's being tested.
//  ================================================================
class DevFooManager : public FooManager
{
public:
	DevFooManager();
	void createNewFoo(int index);
};

//  ================================================================
//	Dev
//	Stuff that's being tested.
//  ================================================================
class DevFooManager2 : public FooManager
{
public:
	DevFooManager2();
	void createNewFoo(int index);
};

//  ================================================================
//	Testing Managers
//	Certain managers designed for certain tests.
//  ================================================================

// has seven foos that each react to a different band
class BandFooManager : public FooManager
{
public:
	BandFooManager();
	void createNewFoo(int index);
};

// testing foos that query system performance
class SystemTests : public FooManager
{
public:
    SystemTests();
    void createNewFoo(int index);
};

// live music listener (should work with processing example)
class ContinuousOutput : public FooManager
{
public:
	ContinuousOutput();
	void createNewFoo(int index);
};

// has meters with flash for beat detection.
class BeatTestingManager : public FooManager
{
public:
	BeatTestingManager();
	void createNewFoo(int index);
};

//  ================================================================
//	Other Shit Managers
//	Made for certain occasions.
//  ================================================================

// all red and green patterns
class ChristmasManager : public FooManager
{
public:
	ChristmasManager();
	void createNewFoo(int index);
};

// all still patterns (for photos)
class StillManager : public FooManager
{
public:
	StillManager(int aBrightness);
	int myBrightness;
	void createNewFoo(int index);
};






#endif


