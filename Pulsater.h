//	########################################################################

//  Pulsater.h

//	1/23/14

//	additional features to add:
//	- change rate of pulsating
//	- after pulse is done, switch 'start' address and change color
//	- mid-pulse, change color if beat is detected
//	- over course of pulse, go through rainbow

//	########################################################################

#ifndef __litHeadbandSimulator__Pulsater__
#define __litHeadbandSimulator__Pulsater__

#include "Foo.h"
#include "LITFunctions.h"

class Pulsater : public Foo
{
public:
	Pulsater();
	void upBrightness();
	void downBrightness();
};



#endif


