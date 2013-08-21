//	########################################################################

//  EMFoo.cpp

//	8/16/13

//	########################################################################

#include "EMFoo.h"

EMFoo::EMFoo()
{
	k = .001;
	
	Step<EMFoo>* aStep = new Step<EMFoo>;
	aStep->fnPtr = &EMFoo::applyForces;
	addStep(aStep);
	
	ChargedFoo* proton1		= new ChargedFoo;
	ChargedFoo* proton2		= new ChargedFoo;
	ChargedFoo* proton3		= new ChargedFoo;
	
	proton1->isPositive		= true;
	proton2->isPositive		= true;
	proton3->isPositive		= true;
	
	proton1->addLEDs(LITColor.green, maxBrightness, 1, 1);
	proton2->addLEDs(LITColor.green, maxBrightness, 12, 12);
	proton3->addLEDs(LITColor.green, maxBrightness, 16,16);
	
	addFoo(proton1);
	addFoo(proton2);
	addFoo(proton3);
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
			Force bForce;
			
			ChargedFoo* bFoo = (ChargedFoo*)foos.entry(n)->me;
			
			int bPos = bFoo->fLEDs.entry(0)->me->address;
			
			double shortD	= shortDistance(bPos, position);
			double longD	= longDistance(bPos, position);
			
			double shortMag = k * bFoo->charge / (shortD*shortD);
			double longMag	= k * bFoo->charge / (longD*longD);
			double netMag	= shortMag - longMag;
			
			if (bFoo->isPositive)
				bForce.direction = shortDirection(bPos, position);
			else
				bForce.direction = !shortDirection(bPos, position);
			
			bForce.magnitude = netMag;
			
			aForce.addForce(bForce);
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