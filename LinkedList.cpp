//	########################################################################

//  LinkedList.cpp

//	7/25/13

//	########################################################################

#include "LinkedList.h"
#include "Foo.h"



template <class T>
ListObject<T>::ListObject()
{
	me   = NULL;
	next = NULL;
}

template <class T>
LinkedList<T>::LinkedList()
{
	start = NULL;
}

template <class T>
int LinkedList<T>::length()
{
	Serial.println("== length()");
	
	int		counter		= 0;
	bool	finished	= 0;
	
	ListObject<T>* tmp = start;
	
	
	while (!finished)
	{
		if (tmp != NULL)
		{
			counter++;
			
			if (tmp->next != NULL)
			{
				tmp = tmp->next;
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

template <class T>
ListObject<T>* LinkedList<T>::entry(int aEntry)
{
	Serial.println("== entry()");
	
	ListObject<T>* tmp = start;
	
	for (int n=0;n<aEntry;n++)
	{
		tmp = tmp->next;
	}
	
	return tmp;
}

template <class T>
void LinkedList<T>::addToEnd(ListObject<T>* newItem)
{
	Serial.println("== addToEnd");
	
	if (length() == 0)
	{
		Serial.println("list length is zero");
		start = newItem;
		
	}
	else
	{
		Serial.println("list length is NOT zero");
		ListObject<T>* last = lastEntry();
		last->next = newItem;
	}
	
}

template <class T>
ListObject<T>* LinkedList<T>::lastEntry()
{
	Serial.println("== lastEntry");
	
	bool finished	= 0;
	
	ListObject<T>* tmpObject = start;
	
	while (!finished)
	{
		if (tmpObject != NULL)
		{
			if (tmpObject->next != NULL)
			{
				tmpObject = tmpObject->next;
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
	
	return tmpObject;
}

template <class T>
void LinkedList<T>::removeEntry(int aEntry)
{
	Serial.println("== removeEntry()");
	
	if (length() == 0)
	{
		start = NULL;
	}
	
	else if (aEntry == length())
	{
		entry(aEntry-1)->next = NULL;
	}
	else if (aEntry == 0)
	{
		start = entry(1);
	}
	else
	{
		ListObject<T>* entryToRemove		= entry(aEntry);
		ListObject<T>* pointerToTransfer	= entryToRemove->next;
		entry(aEntry-1)->next				= pointerToTransfer;
	}
}

template <class T>
void LinkedList<T>::removeAllEntries()
{
	while (length() > 0)
	{
		removeEntry(0);
	}
}



template class LinkedList<LED>;
template class ListObject<LED>;

template class LinkedList<AddressedLED>;
template class ListObject<AddressedLED>;

template class LinkedList<Foo>;
template class ListObject<Foo>;













