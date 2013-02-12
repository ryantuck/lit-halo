//	####################################################################
//
//	LPD8806.h
//
//	placeholder file for compiling arduino code in Xcode.
//
//	####################################################################

#ifndef ____LPD8806__
#define ____LPD8806__

class LPD8806
{
public:
	LPD8806();
	LPD8806(int a, int b, int c);
	void setPixelColor(int n,int r,int g,int b);
	void begin();
	void show();
};

#endif
