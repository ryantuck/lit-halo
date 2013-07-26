//	########################################################################

//  LinkedList.h

//	7/25/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__LinkedList__
#define __LIT_Headband_Simulator__LinkedList__

#include "LIT.h"
#include "MetaEntity.h"


template <class T>
class ListObject
{
public:
	ListObject();
	T	me;
	ListObject<T>*	next;
	
public:
};

template <class T>
class LinkedList
{
public:
	LinkedList();
	
	ListObject<T>* start;
	
	int length();
	
	ListObject<T>* lastEntry();
	
	ListObject<T>* entry(int aEntry);
	
	void addToEnd(ListObject<T>* newItem);
	
	void removeEntry(int aEntry);
	
};






#endif


