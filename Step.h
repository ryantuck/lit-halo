//	########################################################################

//  Step.h

//	8/12/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__Step__
#define __LIT_Headband_Simulator__Step__

#include "LIT.h"

template <class T>
class Step
{
public:
	Step();
	
	void	(T::*fnPtr)();
	
	int		count;
	int		currentCount;
	
	int		period;
	int		periodCounter;
	
	bool	isFinished;
	
	void iterate();
	bool canUpdate();
};



#endif


