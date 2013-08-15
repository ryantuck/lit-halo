//	####################################################################

//	Color.h

//	*	Simply r,g,b.

//	####################################################################

#ifndef ____Color__
#define ____Color__

#include "Arduino.h"

class Color
{
public:
	
	byte r;
	byte g;
	byte b;
	
	//	Constructors [default r,g,b = 1,69,100]
	Color();
	Color(byte red,byte green, byte blue);
	
	//	Sets current color's rgb values to input
	void setColor(Color newColor);
	void setColor(byte red,byte green,byte blue);
	
	//	Averages current color with input
	void mixWith(Color otherColor);
	void mixWith(byte red, byte green, byte blue);
	
	//	Adds inputs to current color's rgb vals
	void add (int dr, int dg, int db);
    
    //convert rgb color to equivalent rgb at specified brightness (0-127)
    void findRGB(byte brightness);
	
	//	For testing
	void printVitals();
	
	
private:
	
	byte check(int newValue);
	
	byte add(int currentValue,int newValue);
	
	byte maxVal(Color newColor);
	byte maxVal(byte red, byte green, byte blue);
	
	byte minVal(Color newColor);
	byte minVal(byte red, byte green, byte blue);
	
	void expandNums();

};

#endif
