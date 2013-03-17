//	####################################################################
//
//	Element.cpp
//
//	####################################################################

#include "Element.h"

Element::Element()
{
	createSegmentsArray(1);
	
	layer		= 1;
	rate		= 1;
	rateCounter = 0;
	io			= 1;
	brightness	= 127;
	numLEDs		= 0;
}

Element::~Element()
{
	//	Should include error checking for previously-freed objects.
	
	for (int n=0;n<numSegments();n++)
	{
		delete segments[n];
		segments[n] = NULL;	// ?
	}
	
	delete [] segments;
	segments = NULL;
		
}

void Element::update()
{
	updateLEDs();
}

void Element::updateLEDs()
{
	byte maxAddress	= numLEDs-1;
	
	if (io)
	{
		for (int a=0;a<numSegments();a++)
		{
			int tmpStart	= segments[a]->start;
			int tmpLength	= segments[a]->length;
			
			for (int b=0; b<tmpLength;b++)
			{
				int tmpAddress = tmpStart + b;
				if (tmpAddress > maxAddress)
					tmpAddress = tmpAddress-maxAddress-1;
                
                
				if (layer > leds[tmpAddress].currentLayer)
				{
					leds[tmpAddress].currentLayer	= layer;
					leds[tmpAddress].brightness		= brightness;
					leds[tmpAddress].color.setColor(segments[a]->color);
                    leds[tmpAddress].adjustColor();
				}
				else if (layer == leds[tmpAddress].currentLayer)
				{
					leds[tmpAddress].brightness = brightness;
					leds[tmpAddress].color.mixWith(segments[a]->color);
					leds[tmpAddress].adjustColor();
				}
			}
		}
	}
}

void Element::move(bool direction)
{
	byte	maxAddress	= numLEDs-1;
	
	for (int n=0;n<numSegments();n++)
	{
		byte tmpStart = segments[n]->start;
		
		tmpStart = updateValue(tmpStart,
							   direction,
							   0,
							   maxAddress,
							   1);
		
		segments[n]->start = tmpStart;
	}
}

void Element::fade(bool direction)
{
	brightness = updateValue(brightness,
							 direction,
							 0,
							 127,
							 0);
}

void Element::riseFall(bool direction)
{
	layer = updateValue(layer,
						direction,
						1,
						10,
						0);
}

void Element::accelerate(bool direction)
{
	rate = updateValue(rate,
					   direction,
					   1,
					   40,
					   0);
}

void Element::switchState()
{
	if (io)	io = 0;
	else	io = 1;
}

bool Element::canUpdate()
{
	if (rateCounter == rate)
	{
		rateCounter = 1;
		return 1;
	}
	else
	{
		rateCounter++;
	}
	
	return 0;
}

int Element::numSegments()
{
	int tmpSum = 0;
	
	for (int n=0;n<maxSegments;n++)
		if (segments[n] != NULL)
			tmpSum++;
	
	return tmpSum;
}



byte Element::updateValue(byte parameter,
						  bool direction,
						  byte minVal,
						  byte maxVal,
						  bool cycles)
{	
	if (direction)
	{
		if (parameter == maxVal)
		{
			if (cycles) parameter = minVal;
			else		parameter = maxVal;
		}
		else parameter++;
	}
	else
	{
		if (parameter == minVal)
		{
			if (cycles)	parameter = maxVal;
			else		parameter = minVal;
		}
		else parameter--;
	}
	
	return parameter;
}

void Element::createSegmentsArray(int number)
{
	maxSegments = number;
	segments = new Segment*[number];
	
	for (int n=0;n<number;n++)
	{
		segments[n] = new Segment;
	}
}



void Element::printVitals()
{	
	Serial.print("# Segments:   ");
	Serial.println(numSegments());
	Serial.print("# LEDs:      ");
	if (numLEDs < 10) Serial.print(" ");
	Serial.println(numLEDs);
	Serial.print("Layer:        ");
	Serial.println(layer);
	Serial.print("Rate:        ");
	if (rate < 10) Serial.print("  ");
	Serial.println(rate);
	Serial.print("IO:           ");
	Serial.println(io);
	Serial.print("Brightness: ");
	if (brightness < 10) Serial.print("  ");
	else if (brightness < 100) Serial.print(" ");
	Serial.println(brightness);
	Serial.println();
}


















