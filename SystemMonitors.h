//	########################################################################

//  SystemMonitors.h

//	11/24/13

//	########################################################################

#ifndef __litHeadbandSimulator__SystemMonitors__
#define __litHeadbandSimulator__SystemMonitors__

#include "Foo.h"
#include <math.h>

class BinaryValue : public Foo
{
public:
	BinaryValue();
	BinaryValue(int aStart);
	void cycle();
	void display();
	
	void changeLEDs(int newVal);
	
	int val;
	int start;
};

class DoubleMonitor : public Foo
{
public:
	DoubleMonitor();
	void checkValues();
};


#endif


