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
	isFinished		= false;
}

template <class T>
void Step<T>::iterate()
{
	currentCount++;
	
	if (currentCount == count)
	{
		isFinished = true;
		currentCount = 0;
	}
}

template class Step<Tester>;
template class Step<Foo>;
template class Step<StepFoo1>;