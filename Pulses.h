//	########################################################################

//  Pulses.h

//	12/19/13

//	########################################################################

#ifndef __litHeadbandSimulator__Pulses__
#define __litHeadbandSimulator__Pulses__

#include "Foo.h"
#include "EphemeralSnakesFoo.h"

class Pulse4 : public Foo
{
public:
	Pulse4();	
	void runIt();
	
private:
	bool	orientation;
	int		colIndex;
};



#endif


