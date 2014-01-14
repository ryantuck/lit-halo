//	####################################################################
//
//	Serial.h
//
//	Replaces cout commands so two copies of code (xcode and arduino)
//		don't have to be kept. 
//
//	####################################################################

#ifndef __cppTesting__Serial__
#define __cppTesting__Serial__

#include <iostream>
#include <string.h>

class SerialClass
{
public:
	
	void print(int integer);
	void print(std::string myString);
	void print(float myFloat);
    void print(double myDouble);
	
	void println();
	void println(int myInt);
	void println(std::string myString);
	void println(float myFloat);
    void println(double myDouble);
};

#endif
