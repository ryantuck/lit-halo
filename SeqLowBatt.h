//	########################################################################

//  SeqLowBatt.h

//	3/16/13

/*
 
 Flashes red lights to let user know to turn the HB off.
 
 */

//	########################################################################


#ifndef __LIT_Source__SeqLowBatt__
#define __LIT_Source__SeqLowBatt__

#include "Sequence.h"
#include "CustomElements.h"
#include "LITColor.h"

class SeqLowBatt : public Sequence
{
public:
	SeqLowBatt();
	void update();
	
	int state;
	
	int longWhileCounter;
};

#endif
