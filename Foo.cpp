//	########################################################################

//  Foo.cpp

//	7/26/13

//	########################################################################

#include "Foo.h"

//	========================================================

Foo::Foo()
{
	foos			= NULL;
	fLEDs			= NULL;
	
	arrayLength		= 0;
	numberOfFoos	= 0;
	numberOfLEDs	= 0;
	
	io				= 1;
	period			= 1;
	layer			= 1;
	buttplug		= 0;
	periodCounter	= 0;
	readyToDie		= 0;
	brightness		= maxBrightness;
}

Foo::~Foo()
{
	destroyArray();
	destroyLEDArray();
}

//	========================================================

void Foo::createArray()
{
	createArray(1);
}

void Foo::createArray(int num)
{
	if (foos == NULL)
	{
		foos = new Foo*[num];
		
		for (int n=0;n<num;n++)
			foos[n] = NULL;
		
		arrayLength = num;
	}
}

//	========================================================

void Foo::resizeArray()
{
	int newLength = arrayLength*2;
	
	Foo** tmpArray;
	tmpArray = new Foo*[newLength];
	
	for (int n=0;n<arrayLength;n++)
	{
		tmpArray[n] = foos[n];
	}
	
	delete foos;
	foos = NULL;
	
	createArray(newLength);
	
	for (int n=0;n<arrayLength;n++)
	{
		foos[n] = tmpArray[n];
	}
	
	delete tmpArray;
	
	arrayLength = newLength;
}

void Foo::clearArray()
{
	if (foos != NULL)
	{
		for (int n=0;n<arrayLength;n++)
		{
			if (foos[n] != NULL)
			{
				delete foos[n];
				foos[n] = NULL;
			}
		}
	}
}

void Foo::destroyArray()
{
	clearArray();
	
	if (foos != NULL)
	{
		delete foos;
		foos = NULL;
	}
	
	arrayLength		= 0;
	numberOfFoos	= 0;
}

//	========================================================

void Foo::addItem()
{
	int  index = 0;
	bool added = 0;
	
	if (foos == NULL)
	{
		createArray();
		foos[0] = new Foo;
		numberOfFoos++;
		added = 1;			// ?
	}
	else if (foos != NULL)
	{
		for (int n=0;n<5;n++)
			if (numberOfFoos == (2^n))
				resizeArray();
		
		while (!added)
		{
			if (foos[index] != NULL && index < numberOfFoos)
			{
				index++;
			}
			else
			{
				foos[index] = new Foo;
				numberOfFoos++;
				added = 1;
			}
		}
	}
}

void Foo::removeItem(int index)
{
	if (foos[index] != NULL)
	{
		delete foos[index];
		foos[index] = NULL;
		numberOfFoos--;
	}
}

//	========================================================

void Foo::setBlock(Color aColor,
				   int aBrightness,
				   int aStart,
				   int aEnd)
{
	// check values
	if (aStart	< 0)			aStart	= 0;
	if (aStart	>= numLEDs)		aStart	= numLEDs;
	if (aEnd	< 0)			aEnd	= 0;
	if (aEnd	>= numLEDs)		aEnd	= numLEDs;
	
	int length = aEnd-aStart+1;
	
	if (fLEDs == NULL)
	{
		createLEDArray(length);
	}
	else
	{
		AddressedLED** tmp = new AddressedLED*[numberOfLEDs];
		
		for (int n=0;n<numberOfLEDs;n++)
			tmp[n] = fLEDs[n];
		delete fLEDs;
		fLEDs = NULL;
		
		createLEDArray(numberOfLEDs+length);
		
		for (int n=0;n<numberOfLEDs;n++)
			fLEDs[n] = tmp[n];
		delete tmp;
		tmp = NULL;
	}
	
	for (int n=0;n<length;n++)
	{
		AddressedLED* tmpLED = new AddressedLED;
		tmpLED->color.setColor(aColor);
		tmpLED->address = aStart+n;
		
		fLEDs[numberOfLEDs+n] = tmpLED;
	}
	
	numberOfLEDs += length;
}

void Foo::createLEDArray(int num)
{
	if (fLEDs == NULL)
	{
		fLEDs = new AddressedLED*[num];
		for (int n=0;n<num;n++)
			fLEDs[n] = NULL;
	}
}

void Foo::destroyLEDArray()
{
	if (fLEDs != NULL)
	{
		for (int n=0;n<numberOfLEDs;n++)
		{
			delete fLEDs[n];
			fLEDs[n] = NULL;
		}
		
		delete fLEDs;
		fLEDs = NULL;
	}
	
	numberOfLEDs = 0;
}

//	========================================================

int Foo::numItems()
{
	return numberOfFoos;
}

int Foo::lengthOfArray()
{
	return arrayLength;
}

//	========================================================

void Foo::iterate()
{
	checkForUpdate();
	updateFoos();
	updateLEDs();
}

void Foo::update()
{
	move(buttplug);
}

void Foo::updateLEDs()
{
	printVitals();
	
	if (io)
	{
		if (fLEDs != NULL)
		{
			for (int n=0;n<numberOfLEDs;n++)
			{
				int addr = fLEDs[n]->address;
				
				if (layer > leds[addr].layer)
				{
					leds[addr].setAttributes(*fLEDs[n]);
					leds[addr].layer = layer;
				}
				else if (layer == leds[addr].layer)
				{					
					fLEDs[n]->brightness = brightness;
					leds[addr].mixWith(*fLEDs[n]);
					leds[addr].adjustColor();
				}
			}
		}
	}
}

void Foo::updateFoos()
{
	if (foos != NULL)
		for (int n=0;n<numberOfFoos;n++)
			foos[n]->iterate();
}

void Foo::checkForUpdate()
{
	periodCounter++;
	
	if (canUpdate())
	{
		update();
		periodCounter = 0;
	}
}

//	========================================================

void Foo::move(bool direction)
{
	for (int n=0;n<numberOfLEDs;n++)
	{
		byte addr = fLEDs[n]->address;
		addr = updateValue(addr, direction, 0, 31, 1);
		fLEDs[n]->address = addr;
	}
}

//	========================================================

byte Foo::updateValue(byte parameter,
					  bool direction,
					  byte minVal,
					  byte maxVal,
					  bool cycles)
{
	if (direction)
	{
		if (parameter == maxVal)
		{
			if (cycles) parameter = minVal;
			else		parameter = maxVal;
		}
		else parameter++;
	}
	else
	{
		if (parameter == minVal)
		{
			if (cycles)	parameter = maxVal;
			else		parameter = minVal;
		}
		else parameter--;
	}
	
	return parameter;
}

bool Foo::canUpdate()
{
	if (periodCounter == period)	return 1;
	else							return 0;
}


void Foo::printVitals()
{
	Serial.println("Foo Vitals");
	Serial.print("number of Foos: "); Serial.println(numberOfFoos);
	Serial.print("number of LEDs: "); Serial.println(numberOfLEDs);
	Serial.print("array length:   "); Serial.println(arrayLength);
}

















