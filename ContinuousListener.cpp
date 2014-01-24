//	########################################################################

//  ContinuousListener.cpp

//	1/24/14

//	########################################################################

#include "ContinuousListener.h"

ContinuousListener::ContinuousListener()
{
	Step<ContinuousListener>* collect = new Step<ContinuousListener>;
	collect->fnPtr = &ContinuousListener::collectData;
	addStep(collect);
	
	Serial.println("==========================");
}

void ContinuousListener::collectData()
{
	for (int n=0;n<7;n++)
	{
		Serial.print(audio.eq.spectrum[n]);
		Serial.print(",");
	}
	Serial.println();
}


