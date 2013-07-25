//	########################################################################

//  LinkedList.h

//	7/25/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__LinkedList__
#define __LIT_Headband_Simulator__LinkedList__

#include "LIT.h"

class LinkedList
{
public:
	LinkedList();
	
	ListedLED* start;
	
	int listLength();
	
	void addToEnd(ListedLED* newLED);
	
	ListedLED* lastEntry();
	ListedLED* entry(int aEntry);
	
	void removeEntry(int aEntry);
};



#endif


