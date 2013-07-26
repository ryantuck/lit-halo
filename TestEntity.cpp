//	########################################################################

//  TestEntity.cpp

//	7/26/13

//	########################################################################

#include "TestEntity.h"

TestEntity::TestEntity()
{
	setBlock(LITColor.red, maxBrightness, 2, 6);
	
	Entity1* tmp1 = new Entity1;
	Entity2* tmp2 = new Entity2;
	
	ListObject<MetaEntity>* tmpA = new ListObject<MetaEntity>;
	ListObject<MetaEntity>* tmpB = new ListObject<MetaEntity>;
	
	tmpA->me = *tmp1;
	tmpB->me = *tmp2;
	
	entities.addToEnd(tmpA);
	entities.addToEnd(tmpB);
}

void TestEntity::update()
{
	
}

