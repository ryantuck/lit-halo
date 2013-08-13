//	########################################################################

//  Step.h

//	8/12/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__Step__
#define __LIT_Headband_Simulator__Step__

template <class T>
class Step
{
public:
	Step();
	
	void	(T::*fnPtr)();
	int		count;
};



#endif


