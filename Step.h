//	########################################################################

//  Step.h

//	8/12/13

//	templates require in-line definitions in h file.

//	########################################################################

#ifndef __LIT_Headband_Simulator__Step__
#define __LIT_Headband_Simulator__Step__

#include "LIT.h"

template <class T>
class Step
{
public:
	Step()
	{
		count			= 0;
		currentCount	= 0;
		period			= 1;
		periodCounter	= 0;
		isFinished		= false;
	}
	
	void	(T::*fnPtr)();
	
	int		count;
	int		currentCount;
	
	int		period;
	int		periodCounter;
	
	bool	isFinished;
	
	void iterate()
	{
		periodCounter = 0;
		currentCount++;
		
		if (currentCount == count)
		{
			isFinished = true;
			currentCount = 0;
		}
	}
	
	bool canUpdate()
	{
		if (periodCounter >= period)	return 1;
		else							return 0;
	}
};


#endif


