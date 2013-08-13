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
	count = 0;
}

template class Step<Tester>;
template class Step<Foo>;
template class Step<ArrayOfFunctionsFoo>;