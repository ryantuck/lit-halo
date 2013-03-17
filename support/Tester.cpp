//	####################################################################
//
//	Tester.cpp
//
//	####################################################################

#include "Tester.h"

Tester tester;

Tester::Tester()
{
	
}


void Tester::colors()
{
	Serial.println("================================");
	Serial.println(" Colors");
	Serial.println("================================");
	Serial.println();
	
	
	Color red	= Color(1,0,0);
	Color green = Color(0,7,0);
	Color blue	= Color(0,0,127);
	
	Serial.println("** Color red   = Color(1,0,0);  **");
	Serial.println("** Color green = Color(0,2,0);  **");
	Serial.println("** Color blue  = Color(0,0,127) **");
	Serial.println();
	
	Serial.print("red   ");	red.printVitals();
	Serial.print("green ");	green.printVitals();
	Serial.print("blue  "); blue.printVitals();
	
	Serial.println();
	Serial.println("** red.mixWith(green);	 **");
	Serial.println();
	
	red.mixWith(green);
	Serial.print("yellow ");	red.printVitals();
	
	Color cyan;
	
	Serial.println();
	Serial.println("** Color cyan;	 **");
	Serial.println("** cyan.setColor(0,1,1);");
	Serial.println();
	
	Serial.print("default ");	cyan.printVitals();
	
	cyan.setColor(0,1,1);
	
	Serial.print("cyan    ");	cyan.printVitals();
}

void Tester::leds()
{
	Serial.println();
	Serial.println("================================");
	Serial.println(" LEDs");
	Serial.println("================================");
	Serial.println();
	
	
	
	LED myLED;
	
	Serial.println();
	Serial.println("** LED defaults **");
	Serial.println();
	
	myLED.printVitals();
	
	Color myColor = Color(100,25,50);
	
	myLED.color			= myColor;
	myLED.brightness	= 75;
	myLED.currentLayer	= 9;
	
	Serial.println();
	Serial.println("** custom color, brightness, layer **");
	Serial.println();
	
	myLED.printVitals();
}

void Tester::segments()
{
	
}

void Tester::elements()
{
	DotElement myDot;
	AlternatingElement myAlt;
	RainbowSnakeElement mySnake;
	
	Serial.println("Dot");
	myDot.printVitals();
	
	for (int n=0;n<myDot.numSegments();n++)
	{
		Serial.print(n);	Serial.print(" ");
		myDot.segments[n]->color.printVitals();
	}
	
	Serial.println("Alt");
	myAlt.printVitals();
	
	for (int n=0;n<myAlt.numSegments();n++)
	{
		Serial.print(n);	Serial.print(" ");
		myAlt.segments[n]->color.printVitals();
	}
	
	Serial.println("Snake");
	mySnake.printVitals();
	
	for (int n=0;n<mySnake.numSegments();n++)
	{
		Serial.print(n);	Serial.print(" ");
		mySnake.segments[n]->color.printVitals();
	}
}

void Tester::sequences()
{
	SeqAltTest mySAT;
	
	for (int n=0;n<mySAT.elements[0]->numSegments();n++)
	{
		Serial.print(n); Serial.print(" ");
		mySAT.elements[0]->segments[n]->color.printVitals();
	}
}

void Tester::patterns()
{
	Pattern1 myPatt;
	
	int x = myPatt.sequences[0]->elements[0]->numSegments();
	
	for (int n=0;n<x;n++)
	{
		Serial.print(n); Serial.print(" ");
		myPatt.sequences[0]->elements[0]->segments[n]->color.printVitals();
	}
}

void Tester::headband()
{
	Headband myHeadband;
	myHeadband.linkUp();
	
	myHeadband.update();
	myHeadband.printLEDs();
	
	for (int n=0;n<200;n++)
	{
		myHeadband.update();
		myHeadband.printLEDs();
	}
}

void Tester::kernTest()
{
    //dummy function
}

void Tester::brightnessTest()
{
	//	Tests Ryan's of brightness control versus findRGB().
	
	Color	myColor;
	LED		myLED;
	
	for (int n=0;n<128;n++)
	{
		//	initial vals
		myColor.setColor(1,5,19);
		myLED.brightness = n;
		myLED.color.setColor(myColor);
		
		//	adjust rgb vals for brightness
		myColor.findRGB(n);
		myLED.adjustColor();
		
		
		Serial.print(n); Serial.print(" Kern: ");
		
		myColor.printVitals();
		
		if (n<10)
			Serial.print("  ");
		else if (n<100)
			Serial.print("   ");
		else
			Serial.print("    ");
		
		Serial.print("Ryan: ");
		
		myLED.color.printVitals();
		
		Serial.println();
	}
	
	
	/*
	 
	 RESULTS
	 
	 *	findRGB() does not jive with the way Color class is already set up. it permanantly changes the color instead of simply returning some combination of color and brightness. This need to be addressed.
	 
	 *	Also, it pretty much does what my code already had done. I was under the impression that the RGB values at full brightness would be different than RGB values at low brightness. As is evident, findRGB() pretty much multiplies numbers linearly.
	 
	 *	Therefore, I propose we address this issue by removing findRGB() from the code for the time being and revert back to my simpler, cleaner code. Also, in the future, new functions should be thoroughly vetted before being added to working code. Just because they are on some wikipedia page does not make them worth having.
	 
	 == Later Edit ==
	 
	 *	RT implemented brightness control in a trivial 4-line function in the LED class. The output of this test compares Ryan's method versus findRGB(), and shows that they do essentially the same thing. While the function still changes the color permanently, this is actually fine when done solely within the scope of an LED. 
	 
	 */
	
}





















