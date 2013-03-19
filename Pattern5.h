//	########################################################################

//  Pattern5.h

//	3/17/13

/*
 
 Creates up to 10 ephemeral snakes on the headband. Currently designed to create them randomly with random colors, layers, lengths, rates, etc. 
 
 */

//	########################################################################

#ifndef __LIT_Source__Pattern5__
#define __LIT_Source__Pattern5__

#include "Pattern.h"
#include "CustomSequences.h"
#include "LITColor.h"

class Pattern5 : public Pattern
{
public:
	Pattern5();
	void update();
};



#endif


