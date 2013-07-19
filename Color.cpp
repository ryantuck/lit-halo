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
	if (newValue > 127)	return 127;
	if (newValue < 0)	return 0;
	
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
	byte max				= checkVals(red);
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
	byte min				= checkVals(red);
	if (green < min)	min = checkVals(green);
	if (blue < min)		min = checkVals(blue);
	return min;
}

void Color::expandNums()
{
	float tmpMax = maxVal(r,g,b);
	
	float ratio = 0;
	
	if (tmpMax != 0)	ratio = 127 / tmpMax;
	
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
	else return 0;
}

void Color::findRGB(byte brightness)
{
    double h,s,v;
    double min, max, delta;
    
    double      hh, p, q, t, ff;
    long        i;
    
    min = r	< g ? r : g;
    min = min < b ? min : b;
        
    max = r > g ? r : g;
    max = max  > b ? max : b;
        
    //v = max;                                    //v
    delta = max - min;
    if( max > 0.0 )
    {
        s = delta / max;                        // s
    }
    else
    {
        // r = g = b = 0                          // s = 0, v is undefined
        s = 0.0;
        h = -1;                                   // its now undefined
    }
    if( r >= max )                           // > is bogus, just keeps compilor happy
        h = ( g - b ) / delta;        // between yellow & magenta
    else
        if( g >= max )
            h = 2.0 + ( b - r ) / delta;  // between cyan & yellow
        else
            h = 4.0 + ( r - g ) / delta;  // between magenta & cyan
        
    h *= 60.0;                              // degrees
        
    if( h < 0.0 )
        h += 360.0;
        
    //set v to brightness
    v = brightness;
    
    if(s <= 0.0) // < is bogus, just shuts up warnings
    {       
        if(h == -1) // h == NAN
        {   
            r = v;
            g = v;
            b = v;
            return;
        }
        // error - should never happen
        r = 0.0;
        g = 0.0;
        b = 0.0;
        return;
    }
    hh = h;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = v * (1.0 - s);
    q = v * (1.0 - (s * ff));
    t = v * (1.0 - (s * (1.0 - ff)));
    
    switch(i)
    {
        case 0:
            r = v;
			g = t;
            b = p;
            break;
        case 1:
            r = q;
            g = v;
            b = p;
            break;
        case 2:
            r = p;
            g = v;
            b = t;
            break;
            
        case 3:
            r = p;
            g = q;
            b = v;
            break;
        case 4:
            r = t;
            g = p;
            b = v;
            break;
        case 5:
        default:
            r = v;
            g = p;
            b = q;
            break;
    }

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
