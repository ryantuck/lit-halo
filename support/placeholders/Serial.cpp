//	####################################################################
//
//	Serial.cpp
//
//	####################################################################


#include "Serial.h"

void SerialClass::print(int integer)
{
	std::cout << integer;
}

void SerialClass::print(std::string myString)
{
	std::cout << myString;
}

void SerialClass::println()
{
	std::cout << std::endl;
}

void SerialClass::println(int myInt)
{
	std::cout << myInt << std::endl;
}

void SerialClass::println(std::string myString)
{
	std::cout << myString << std::endl;
}

