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

class DevFooManager : public FooManager
{
public:
	DevFooManager();
	void createNewFoo(int index);
};

class BandFooManager : public FooManager
{
public:
	BandFooManager();
	void createNewFoo(int index);
};

class MonoBandFooManager : public FooManager
{
public:
	MonoBandFooManager();
	void createNewFoo(int index);
};

class SingleTestManager : public FooManager
{
public:
	SingleTestManager();
	void createNewFoo(int index);
};

class Tests : public FooManager
{
public:
	Tests();
	void createNewFoo(int index);
};

class AudioTester : public FooManager
{
public:
	AudioTester();
	void createNewFoo(int index);
};

class BestFooManager : public FooManager
{
public:
	BestFooManager();
	void createNewFoo(int index);
};

class VarTester : public FooManager
{
public:
	VarTester();
	void createNewFoo(int index);
};

class ChristmasManager : public FooManager
{
public:
	ChristmasManager();
	void createNewFoo(int index);
};

class JoshManager : public FooManager
{
public:
	JoshManager();
	void createNewFoo(int index);
};


#endif


