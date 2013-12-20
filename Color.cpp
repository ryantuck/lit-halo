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
	r = checkVals(red);
	g = checkVals(green);
	b = checkVals(blue);
	
	expandNums();
}

void Color::setColor(Color newColor)
{
	r = checkVals(newColor.r);
	g = checkVals(newColor.g);
	b = checkVals(newColor.b);
	
	expandNums();
}

void Color::setColor(byte red,byte green,byte blue)
{
	r = checkVals(red);
	g = checkVals(green);
	b = checkVals(blue);
	
	expandNums();
}

void Color::mixWith(Color otherColor)
{
//	expandNums();
//	otherColor.expandNums();
	
	int tmpR = (r + otherColor.r) / 2;
	int tmpG = (g + otherColor.g) / 2;
	int tmpB = (b + otherColor.b) / 2;
	
	byte				tmpMax = tmpR;
	if (tmpG > tmpMax)	tmpMax = tmpG;
	if (tmpB > tmpMax)	tmpMax = tmpB;
	
	if (tmpMax != 0)
	{
		float ratio = maxRGB/tmpMax;
		tmpR *= ratio;
		tmpG *= ratio;
		tmpB *= ratio;
	}
	
	r = checkVals(tmpR);
	g = checkVals(tmpG);
	b = checkVals(tmpB);
}

void Color::add(int dr, int dg, int db)
{
	expandNums();
	
	r = checkVals(r+dr);
	g = checkVals(g+dg);
	b = checkVals(b+db);
}

byte Color::checkVals(int newValue)
{
	if (newValue > maxRGB)	return maxRGB;
	if (newValue < 0)		return 0;
	
	return newValue;
}

byte Color::add(int currentValue,int newValue)
{
	return checkVals(currentValue+newValue);
}

byte Color::maxVal(Color newColor)
{
	return maxVal(newColor.r, newColor.g, newColor.b);
}

byte Color::maxVal(byte red, byte green, byte blue)
{
	byte				max = checkVals(red);
	if (green > max)	max = checkVals(green);
	if (blue  > max)	max = checkVals(blue);
	return max;
}

byte Color::minVal(Color newColor)
{
	return minVal(newColor.r, newColor.g, newColor.b);
}

byte Color::minVal(byte red, byte green, byte blue)
{
	byte				min = checkVals(red);
	if (green < min)	min = checkVals(green);
	if (blue < min)		min = checkVals(blue);
	return min;
}

void Color::calculateRGB(int total, int entry)
{
	int base		= (3 * entry) / total;
	int remainder	= (3 * entry) % total;
	
	if (base==0)
	{
		r = total - remainder;
		g = remainder;
	}
	else if (base==1)
	{
		g = total - remainder;
		b = remainder;
	}
	else if (base==2)
	{
		b = total-remainder;
		r = remainder;
	}
}

void Color::expandNums()
{
	float tmpMax = maxVal(r,g,b);
	
	float ratio = 0;
	
	if (tmpMax != 0)	ratio = maxRGB / tmpMax;
	
	int tmpR = r*ratio;
	int tmpG = g*ratio;
	int tmpB = b*ratio;
	
	r = checkVals(tmpR);
	g = checkVals(tmpG);
	b = checkVals(tmpB);
}

bool Color::isBlack()
{
	if (r == 0 && b == 0 && g == 0) return 1;
	else							return 0;
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

SRTrio::SRTrio()
{
	srR = 0;
	srG = 0;
	srB = 0;
}
