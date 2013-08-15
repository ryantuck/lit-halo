//	####################################################################

//	AlternatingElement.h

//	*	8 identical segments that alternate addresses.

//	####################################################################

#ifndef ____AlternatingElement__
#define ____AlternatingElement__

#include "Element.h"

class AlternatingElement : public Element
{
public:
	AlternatingElement();
	AlternatingElement(Color newColor,bool odds);
};

#endif
