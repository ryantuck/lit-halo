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
				finished = true;
			}
		}
		else
		{
			finished = true;
		}
	}

	return counter;
}

template <class T>
ListObject<T>* LinkedList<T>::entry(int aEntry)
{
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
	if (length() == 0)
	{
		start = newItem;
	}
	else
	{
		ListObject<T>* last = lastEntry();
		last->next = newItem;
	}
	
}

template <class T>
ListObject<T>* LinkedList<T>::lastEntry()
{
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
	if (length() == 0)
	{
		start = NULL;
	}
	else if (aEntry >= length())
	{
		Serial.println("aEntry too large");
	}
	else
	{
		if (aEntry == 0)
		{
			delete entry(aEntry)->me;
			ListObject<T>* ptrToPass = entry(aEntry)->next;
			delete entry(aEntry);
			start = ptrToPass;
		}
		else if (aEntry == length() - 1)
		{
			delete entry(aEntry)->me;
			ListObject<T>* ptrToPass = entry(aEntry)->next;
			delete entry(aEntry);
			entry(aEntry-1)->next = ptrToPass;
		}
		else
		{
			delete entry(aEntry)->me;
			ListObject<T>* entryToRemove = entry(aEntry);
			ListObject<T>* ptrToPass = entryToRemove->next;
			delete entry(aEntry);
			entry(aEntry-1)->next = ptrToPass;
		}
	}
	
	
//	else if (aEntry == 0)
//	{
//		delete entry(aEntry)->me;
//		start = entry(1);
//	}
//	else if (aEntry == length()-1)
//	{
//		delete entry(aEntry)->me;
//		entry(aEntry-1)->next = NULL;
//	}
//	else if (aEntry < length()-1)
//	{
//		delete entry(aEntry)->me;
//		ListObject<T>* entryToRemove		= entry(aEntry);
//		ListObject<T>* pointerToTransfer	= entryToRemove->next;
//		entry(aEntry-1)->next				= pointerToTransfer;
//	}
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

template class LinkedList<Step<Foo> >;
template class ListObject<Step<Foo> >;












