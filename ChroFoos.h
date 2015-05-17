//	########################################################################

//  ChroFoos.h

//	5/16/15

//	########################################################################

#ifndef __ChroFoos__
#define __ChroFoos__

#include "Foo.h"
#include "MovingFoo.h"
#include "EphemeralSnakesFoo.h"
#include "RainbowLine.h"
#include <math.h>
#include "LITFunctions.h"
#include "SystemMonitors.h"
#include "Stats.h"
#include "BandMeterFoo.h"
#include "InAndOutFader.h"
#include "StillFoos.h"
#include "Sparkle.h"

#include "RainbowFountain.h"
#include "RainbowPulser.h"
#include "EphemeralSnakesFoo.h"
#include "TwoColorParticleJam.h"
#include "StillFoos.h"
#include "AllSingleColors.h"
#include "RainbowLine.h"


class ScrollingRainbow : public RainbowLine
{
public:
    ScrollingRainbow(int length, int start) : RainbowLine(length, start)
    {
        addStepWithFunction(&MovingFoo::move,1);
    }
};



#endif







































