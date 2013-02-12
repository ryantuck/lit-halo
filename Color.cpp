//	####################################################################
//
//	Color.cpp
//
//	####################################################################

#include "Color.h"

Color::Color()
{
	r = 1;
	g = 69;
	b = 100;
}

Color::Color(byte red, byte green, byte blue)
{
	r = check(red);
	g = check(green);
	b = check(blue);
	
	expandNums();
}

void Color::setColor(Color newColor)
{
	r = check(newColor.r);
	g = check(newColor.g);
	b = check(newColor.b);
	
	expandNums();
}

void Color::setColor(byte red,byte green,byte blue)
{
	r = check(red);
	g = check(green);
	b = check(blue);
	
	expandNums();
}

void Color::mixWith(Color otherColor)
{
	expandNums();
	otherColor.expandNums();
	
	int tmpR = (r + otherColor.r) / 2;
	int tmpG = (g + otherColor.g) / 2;
	int tmpB = (b + otherColor.b) / 2;
	
	byte tmpMax = tmpR;
	if (tmpG > tmpMax) tmpMax = tmpG;
	if (tmpB > tmpMax) tmpMax = tmpB;
	
	if (tmpMax != 0)
	{
		float ratio = 127/tmpMax;
		tmpR *= ratio;
		tmpG *= ratio;
		tmpB *= ratio;
	}
	
	r = check(tmpR);
	g = check(tmpG);
	b = check(tmpB);
}

void Color::add(int dr, int dg, int db)
{
	expandNums();
	
	r = check(r+dr);
	g = check(g+dg);
	b = check(b+db);
}

byte Color::check(int newValue)
{
	if (newValue > 127)	return 127;
	if (newValue < 0)	return 0;
	
	return newValue;
}

byte Color::add(int currentValue,int newValue)
{
	return check(currentValue+newValue);
}

byte Color::maxVal(Color newColor)
{
	return maxVal(newColor.r, newColor.g, newColor.b);
}

byte Color::maxVal(byte red, byte green, byte blue)
{
	byte max				= check(red);
	if (green > max)	max = check(green);
	if (blue  > max)	max = check(blue);
	return max;
}

byte Color::minVal(Color newColor)
{
	return minVal(newColor.r, newColor.g, newColor.b);
}

byte Color::minVal(byte red, byte green, byte blue)
{
	byte min				= check(red);
	if (green < min)	min = check(green);
	if (blue < min)		min = check(blue);
	return min;
}

void Color::expandNums()
{
	byte tmpMax = maxVal(r,g,b);
	
	float ratio = 0;
	
	if (tmpMax != 0)	ratio = 100 / tmpMax;
	
	int tmpR = r*ratio;
	int tmpG = g*ratio;
	int tmpB = b*ratio;
	
	r = check(tmpR);
	g = check(tmpG);
	b = check(tmpB);
}




void Color::printVitals()
{
	Serial.print("rgb:  ");
	if (r<10)
		Serial.print("[   ");
	else if (r<100)
		Serial.print("[  ");
	else
		Serial.print("[ ");
	Serial.print(r);
	if (g<10)
		Serial.print(" |   ");
	else if (g<100)
		Serial.print(" |  ");
	else
		Serial.print(" | ");
	Serial.print(g);
	if (b<10)
		Serial.print(" |   ");
	else if (b<100)
		Serial.print(" |  ");
	else
		Serial.print(" | ");
	Serial.print(b);
	Serial.print(" ]");
	Serial.println();
}
