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

// in progress testing
class DevFooManager : public FooManager
{
public:
	DevFooManager();
	void createNewFoo(int index);
};

// has seven foos that each react to a different band
class BandFooManager : public FooManager
{
public:
	BandFooManager();
	void createNewFoo(int index);
};

class NonAudioManager : public FooManager
{
public:
	NonAudioManager();
	void createNewFoo(int index);
};

class AudioFooManager : public FooManager
{
public:
	AudioFooManager();
	void createNewFoo(int index);
};

// testing foos that query system performance
class SystemTests : public FooManager
{
public:
    SystemTests();
    void createNewFoo(int index);
};


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
	StillManager();
	void createNewFoo(int index);
};

// live music listener (should work with processing example)
class ContinuousOutput : public FooManager
{
public:
	ContinuousOutput();
	void createNewFoo(int index);
};




#endif


