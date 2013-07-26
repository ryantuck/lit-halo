//	########################################################################

//  Foo.cpp

//	7/26/13

//	########################################################################

#include "Foo.h"


Foo::Foo()
{
	foos = NULL;
	
	arrayLength = 0;
	numberOfFoos = 0;
}

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

void Foo::clearArray()
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

void Foo::destroyArray()
{
	clearArray();
	
	delete foos;
	foos = NULL;
	
	arrayLength		= 0;
	numberOfFoos	= 0;
}

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

int Foo::numItems()
{
	return numberOfFoos;
}

int Foo::lengthOfArray()
{
	return arrayLength;
}

void Foo::addItem()
{
	int  index = 0;
	bool added = 0;
	
	if (numberOfFoos > 0)
	{
		while (index < numberOfFoos && added == 0)
		{
			if (foos[index] != NULL)
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
	else if (foos != NULL)
	{
		foos[0] = new Foo;
		numberOfFoos++;
	}
	
	if (added == 0)
	{
		int tmp = numberOfFoos;
		resizeArray();
		foos[tmp+1] = new Foo;
		numberOfFoos++;
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





























