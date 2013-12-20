//	####################################################################
//
//	Tester.h
//
//	####################################################################

#ifndef ____Tester__
#define ____Tester__

#include <iostream>
using namespace std;
#include "Headband.h"
#include "Arduino.h"
#include "LIT.h"
#include "LinkedList.h"
#include "Foo.h"



class Tester
{
public:

	Tester();
	
	void functionTesting();
	
	void sizeTest();
	
	void funcPtrTest();
	void doAFunction(void (Tester::*func)());
	void doAFunction(void (Tester::*func)(int),int b);
	void printThis(int);
	void printALine();
	
	void linkedListFoo();
	void fooTest();
	
	void fooTester();
	
	void entityWithinEntity();
	
	void templateTesting();
	void linkedListTest();
	
	void ledColorMixingTest();
	
	void things();
	
	void colors();
	void leds();
	void segments();
	void elements();
	void sequences();
	void patterns();
	void headband();
	
	void brightnessTest();
	
	void kernTest();

};

extern Tester tester;

#endif
