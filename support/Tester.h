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



class Tester
{
public:

	Tester();

	void colors();
	void leds();
	void segments();
	void elements();
	void sequences();
	void patterns();
	void headband();
	
	void kernTest();

};

extern Tester tester;

#endif
