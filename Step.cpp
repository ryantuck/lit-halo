//	########################################################################

//  Step.cpp

//	8/12/13

//	########################################################################

#include "Step.h"
#include "Tester.h"
#include "Foo.h"
#include "CustomFoos.h"

template <class T>
Step<T>::Step()
{
	count			= 0;
	currentCount	= 0;
	period			= 1;
	periodCounter	= 0;
	isFinished		= false;
}

template <class T>
void Step<T>::iterate()
{
	periodCounter = 0;
	currentCount++;
	
	if (currentCount == count)
	{
		isFinished = true;
		currentCount = 0;
	}
}

template <class T>
bool Step<T>::canUpdate()
{
	if (periodCounter >= period)	return 1;
	else							return 0;
}


template class Step<Tester>;
template class Step<Foo>;
template class Step<StepFoo1>;
template class Step<RainbowFoo>;
template class Step<LinkedFoo>;
template class Step<KernFoo>;
template class Step<Foo2>;
template class Step<EventFoo>;
template class Step<MovingFoo>;
template class Step<MultipleBouncingFoo>;
template class Step<OscillatingFoo>;





