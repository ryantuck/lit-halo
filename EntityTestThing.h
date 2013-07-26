//	########################################################################

//  EntityTestThing.h

//	7/26/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__EntityTestThing__
#define __LIT_Headband_Simulator__EntityTestThing__

#include "Thing.h"
#include "Entity.h"
#include "TestEntity.h"

class EntityTestThing : public Thing
{
public:
	EntityTestThing();
	
	TestEntity myEnt;
	
	void update();
};



#endif


