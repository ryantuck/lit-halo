//	####################################################################

//	RainbowSnakeElement.cpp

//	####################################################################


#include "RainbowSnakeElement.h"

RainbowSnakeElement::RainbowSnakeElement()
{
	createSegmentsArray(6);
	
	for (int n=0;n<maxSegments;n++)
		segments[n] = new Segment(*LITColor.colorList[n],1,n);
	
}