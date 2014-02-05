//	########################################################################

//  LinkedList.h

//	7/25/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__LinkedList__
#define __LIT_Headband_Simulator__LinkedList__

//#include "LIT.h"
//#include "Step.h"
#include "Arduino.h"

template <class T>
class ListObject
{
public:
	ListObject();
	T*	me;
	ListObject<T>*	next;
};

template <class T>
class LinkedList
{
public:
	LinkedList();
	
	int length();
	
	ListObject<T>* start;
	ListObject<T>* lastEntry();
	ListObject<T>* entry(int aEntry);
	
	void addToEnd(ListObject<T>* newItem);
	void removeEntry(int aEntry);
	
	void removeAllEntries();
	
};






#endif


