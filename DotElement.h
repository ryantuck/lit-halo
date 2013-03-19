//	####################################################################

//	DotElement.h

//	*	Single dot Element.

//	####################################################################

#ifndef ____DotElement__
#define ____DotElement__

#include "Element.h"
#include "LITColor.h"

class DotElement : public Element
{
public:
	DotElement();
	DotElement(Color myColor, int myStart);
};


#endif
