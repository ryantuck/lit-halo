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
	
	//expandNums();
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
	float tmpMax = maxVal(r,g,b);
	
	float ratio = 0;
	
	if (tmpMax != 0)	ratio = 100 / tmpMax;
	
	int tmpR = r*ratio;
	int tmpG = g*ratio;
	int tmpB = b*ratio;
	
	r = check(tmpR);
	g = check(tmpG);
	b = check(tmpB);
}

void Color::findRGB(byte brightness)
{
    double h,s,v;
    double min, max, delta;
    
    double      hh, p, q, t, ff;
    long        i;
    
    min = this->r < this->g ? this->r : this->g;
    min = min  < this->b ? min  : this->b;
        
    max = this->r > this->g ? this->r : this->g;
    max = max  > this->b ? max  : this->b;
        
    //v = max;                                    //v
    delta = max - min;
    if( max > 0.0 )
    {
        s = (delta / max);                        // s
    }
    else
    {
        // r = g = b = 0                          // s = 0, v is undefined
        s = 0.0;
        h = -1;                                   // its now undefined
    }
    if(this->r >= max )                           // > is bogus, just keeps compilor happy
        h = ( this->g - this->b ) / delta;        // between yellow & magenta
    else
        if( this->g >= max )
            h = 2.0 + ( this->b - this->r ) / delta;  // between cyan & yellow
        else
            h = 4.0 + ( this->r - this->g ) / delta;  // between magenta & cyan
        
    h *= 60.0;                              // degrees
        
    if( h < 0.0 )
        h += 360.0;
        
    //set v to brightness
    v = brightness;
    
    if(s <= 0.0) // < is bogus, just shuts up warnings
    {       
        if(h == -1) // h == NAN
        {   
            this->r = v;
            this->g = v;
            this->b = v;
            return;
        }
        // error - should never happen
        this->r = 0.0;
        this->g = 0.0;
        this->b = 0.0;
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
            this->r = v;
            this->g = t;
            this->b = p;
            break;
        case 1:
            this->r = q;
            this->g = v;
            this->b = p;
            break;
        case 2:
            this->r = p;
            this->g = v;
            this->b = t;
            break;
            
        case 3:
            this->r = p;
            this->g = q;
            b = v;
            break;
        case 4:
            this->r = t;
            this->g = p;
            this->b = v;
            break;
        case 5:
        default:
            this->r = v;
            this->g = p;
            this->b = q;
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
