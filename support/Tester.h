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
#include "Serial.h"



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
	
	void movingDotSequenceTester();
	
	
	void bigTester();
	
	void colorTester();
	void ledTester();
	void segmentTester();
	void elementTester();
	void sequenceTester();
	void patternTester();
	void headbandTester();
	void AudioTester();
	
	void tempTester();
	
	void pointerToFunctionTester();
	
	void updateLEDsTester();
	
	void littleTester();
	
	void latestTester();
	
	void newTester();

	void FooTester();
	
	void alphaTester();
	
	void templateTester();
	
	void arduinoTester();
	
	void aTester();
};

extern Tester tester;

#endif
