//	########################################################################

//  Force.h

//	8/20/13

//	########################################################################

#ifndef __LIT_Headband_Simulator__Force__
#define __LIT_Headband_Simulator__Force__

class Force
{
public:
	Force();
	double	magnitude;
	bool	direction;
	
	void addForce(Force otherForce);
};



#endif


