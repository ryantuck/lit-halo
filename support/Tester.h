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
#include "Thing1.h"
#include "LIT.h"
#include "LinkedList.h"
#include "Entity.h"



class Tester
{
public:

	Tester();
	
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
