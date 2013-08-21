//	########################################################################

//  EMFoo.cpp

//	8/16/13

//	########################################################################

#include "EMFoo.h"

EMFoo::EMFoo()
{
	k = 1;
	
	Step<EMFoo>* aStep = new Step<EMFoo>;
	
	aStep->fnPtr = &EMFoo::applyForces;
	
	addStep(aStep);
	
	ChargedFoo* proton1		= new ChargedFoo;
	ChargedFoo* proton2		= new ChargedFoo;
	ChargedFoo* electron1	= new ChargedFoo;
	
	proton1->isPositive		= true;
	proton2->isPositive		= true;
	electron1->isPositive	= false;
	
	addFoo(proton1);
	addFoo(proton2);
	addFoo(electron1);
}

Force EMFoo::calculateForceOnFoo(Foo* aFoo)
{
	Force aForce;
	
	int fooEntry = 0;

	bool done = 0;
	
	while (!done)
	{
		if (foos.entry(fooEntry)->me == aFoo)	done = true;
		else									fooEntry++;
	}
	
	int position = foos.entry(fooEntry)->me->fLEDs.entry(0)->me->address;
	
	for (int n=0;n<countFoos();n++)
	{
		if (fooEntry != n)
		{
			ChargedFoo* bFoo = (ChargedFoo*)foos.entry(n)->me;
			
			int bPos = bFoo->fLEDs.entry(0)->me->address;
			
			int distance = position - bPos;
			
			double tmpMag = k * bFoo->charge / (distance*distance);
			
			aForce.magnitude += tmpMag;
		}
	}
	
	return aForce;
}

void EMFoo::applyForces()
{
	for (int n=0;n<countFoos();n++)
	{
		ChargedFoo* aFoo = (ChargedFoo*)foos.entry(n)->me;
		
		Force aForce = calculateForceOnFoo(aFoo);
		
		aFoo->reactToForce(aForce);
	}
}