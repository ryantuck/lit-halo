//	########################################################################

//  WholeElement.cpp

//	3/16/13

//	########################################################################

#include "WholeElement.h"

WholeElement::WholeElement()
{
	clearSegments();
    createSegmentsArray(16);
    
    for(int n=0; n<maxSegments; n++)
		segments[n] = new Segment(LITColor.white,1,n);
    
    layer		= 1;
    rate		= 1;
    brightness	= 127;
    io			= 1;
}
		
