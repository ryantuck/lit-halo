//	########################################################################

//  LinkedList.cpp

//	7/25/13

//	########################################################################

#include "LinkedList.h"


LinkedList::LinkedList()
{
	start = NULL;
}

int LinkedList::listLength()
{
	int		counter		= 0;
	bool	finished	= 0;
	
	ListedLED* currentLED;
	currentLED = start;
	
	while (!finished)
	{
		if (currentLED != NULL)
		{
			counter++;
			Serial.println("current LED isn't null");
			if (currentLED->next != NULL)
			{
				currentLED = currentLED->next;
			}
			else
			{
				finished = 1;
			}
		}
		else
		{
			finished = 1;
		}
	}
	
	return counter;
}

void LinkedList::addToEnd(ListedLED* newLED)
{
	if (listLength() == 0)
	{
		Serial.println("list length is zero");
		start = newLED;
		
	}
	else
	{
		Serial.println("list length is NOT zero");
		ListedLED* last = lastEntry();
		last->next = newLED;
	}
}

ListedLED* LinkedList::lastEntry()
{
	bool finished	= 0;
	
	ListedLED* currentLED;
	currentLED = start;
	
	while (!finished)
	{
		if (currentLED != NULL)
		{
			if (currentLED->next != NULL)
			{
				currentLED = currentLED->next;
			}
			else
			{
				finished = 1;
			}
		}
		else
		{
			finished = 1;
		}
		
		
	}
	
	return currentLED;
}

ListedLED* LinkedList::entry(int aEntry)
{
	ListedLED* currentLED;
	currentLED = start;
	
	for (int n=0;n<aEntry;n++)
	{
		currentLED = currentLED->next;
	}
	
	return currentLED;
}

void LinkedList::removeEntry(int aEntry)
{
	if (listLength() == 0)
	{
		start = NULL;
	}
	
	else if (aEntry == listLength())
	{
		entry(aEntry-1)->next = NULL;
	}
	else if (aEntry == 0)
	{
		start = entry(1);
	}
	else
	{
		ListedLED* entryToRemove		= entry(aEntry);
		ListedLED* pointerToTransfer	= entryToRemove->next;
		entry(aEntry-1)->next			= pointerToTransfer;
	}
	
	
	
}









