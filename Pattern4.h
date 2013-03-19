//	########################################################################

//  Pattern4.h

//	3/17/13

/*
 
 Contains six moving dots, one for each primary color. They move around at various rates and directions. 
 
 */

//	########################################################################

#ifndef __LIT_Source__Pattern4__
#define __LIT_Source__Pattern4__

#include "Pattern.h"
#include "CustomSequences.h"
#include "LITColor.h"

class Pattern4 : public Pattern
{
public:
	Pattern4();
	void update();
	
};



#endif


