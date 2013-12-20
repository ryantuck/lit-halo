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

<<<<<<< HEAD
=======
void Tester::functionTesting()
{
	int a = shortDistance(0, 16);
	int b = longDistance(0, 16);
	
	Serial.println(a);
	Serial.println(b);
	
	Force aForce;
	Force bForce;
	
	aForce.magnitude = 10;
	aForce.direction = 1;

	bForce.magnitude = 5;
	bForce.direction = 0;
	
	bForce.addForce(aForce);
	
	Serial.println((int)bForce.magnitude);
	Serial.println(bForce.direction);
}

void Tester::sizeTest()
{
	Foo* aFoo = new Foo;
	Foo* bFoo = new Foo;
	
	aFoo->addFoo(bFoo);

	LinkedList<Foo> myList;
	ListObject<Foo> aListObject;
	
	int ptrSize			= sizeof(aFoo);
	int fooSize			= sizeof(*aFoo);
	int fooListSize		= sizeof(aFoo->foos);
	int listSize		= sizeof(myList);
	int listObjectSize	= sizeof(aListObject);
	int boolSize		= sizeof(aFoo->repeats);
	
	Serial.print("ptr: ");			Serial.println(ptrSize);
	Serial.print("foo: ");			Serial.println(fooSize);
	Serial.print("list: ");			Serial.println(listSize);
	Serial.print("foo list: ");		Serial.println(fooListSize);
	Serial.print("list object: ");	Serial.println(listObjectSize);
	Serial.print("bool: ");			Serial.println(boolSize);
}

void Tester::printThis(int a)
{
	Serial.println(a);
}

void printSomething()
{
	Serial.println("butts");
}

void doSomething(void (*funcPtr)())
{
	(*funcPtr)();
}

void Tester::printALine()
{
	Serial.println("blah blah");
}

void Tester::doAFunction(void (Tester::*func)())
{
	(tester.*func)();
}

void Tester::doAFunction(void (Tester::*func)(int),int b)
{
	(tester.*func)(b);
}

void Tester::funcPtrTest()
{
	void (Tester::*pointerToFunction)(int);	// creates a pointer to a function
	pointerToFunction = &Tester::printThis;	// assigns a function to the ptr
	(tester.*pointerToFunction)(1);	//	passes 1 as an argument to the ptr
	doAFunction(pointerToFunction,4);	//	passes the ptr to a function
	
	void (Tester::*ptrToFunc2)();
	ptrToFunc2 = &Tester::printALine;
	doAFunction(ptrToFunc2);
	
	// using casting to allow for array creation
	typedef void (Tester::*genericFP)();
	typedef void (Tester::*intPointer)(int);
	typedef void (Tester::*voidPointer)();
	genericFP fnPtrs[2] = {(genericFP)pointerToFunction,(genericFP)ptrToFunc2};
	doAFunction((intPointer)fnPtrs[0],6);
	doAFunction((voidPointer)fnPtrs[1]);
	
	Step<Tester> myStep;
	myStep.fnPtr = &Tester::printALine;
	doAFunction(myStep.fnPtr);
}

void Tester::linkedListFoo()
{
	ListObject<Foo>* ptrToLO = new ListObject<Foo>;
	Foo aFoo;
	aFoo.foos.addToEnd(ptrToLO);
	
	ListObject<Foo>* ptrToLO2 = new ListObject<Foo>;
	aFoo.foos.addToEnd(ptrToLO2);
	
	Serial.print("length is: ");
	Serial.println(aFoo.foos.length());
}

void Tester::fooTest()
{
	Foo aFoo;
	Foo bFoo;
	Foo cFoo;
	
	Foo* bPtr = &bFoo;
	
	aFoo.addFoo(bPtr);
	aFoo.addFoo(&cFoo);
	
	Serial.print("foo list length: ");
	Serial.println(aFoo.foos.length());
	
	bFoo.addLEDs(LITColor.green, maxBrightness, 4, 19);
	
	Serial.print("bFoo contains x LEDs: ");
	Serial.println(aFoo.foos.entry(0)->me->fLEDs.length());
	
	cFoo.addLEDs(LITColor.pink, maxBrightness, 1, 25);
	
	Serial.print("cFoo contains x LEDs: ");
	Serial.println(aFoo.foos.entry(1)->me->fLEDs.length());
}




void Tester::fooTester()
{
//	Foo aFoo;
//	
//	aFoo.createArray();
//	aFoo.addItem();
//	
//	aFoo.foos[0]->createArray();
//	aFoo.foos[0]->addItem();
//	
//	aFoo.direction = 1;
//	
//	aFoo.foos[0]->direction = 1;
//	
//	Serial.println(aFoo.foos[0]->direction);
//	
//	//aFoo.createLEDArray(5);
//	
//	aFoo.setBlock(LITColor.orange, maxBrightness, 13, 19);
//	
//	Serial.println("end of fooTester");
}

void Tester::templateTesting()
{	
	LinkedList<LED> myList;
	
	ListObject<LED>* aLED = new ListObject<LED>;
	ListObject<LED>* bLED = new ListObject<LED>;
	ListObject<LED>* cLED = new ListObject<LED>;
	ListObject<LED> dLED;
	
	ListObject<LED>* ptr = &dLED;
	
	myList.addToEnd(aLED);
	myList.addToEnd(bLED);
	myList.addToEnd(cLED);
	myList.addToEnd(ptr);
	
	Serial.println(myList.length());
}


void Tester::linkedListTest()
{
//	LinkedList myList;
//	
//	ListedLED* aLED = new ListedLED;
//	ListedLED* bLED = new ListedLED;
//	ListedLED* cLED = new ListedLED;
//	ListedLED* dLED = new ListedLED;
//	
//	aLED->color.setColor(LITColor.red);
//	bLED->color.setColor(LITColor.yellow);
//	cLED->color.setColor(LITColor.green);
//	dLED->color.setColor(LITColor.cyan);
//	
//	myList.addToEnd(aLED);
//	myList.addToEnd(bLED);
//	myList.addToEnd(cLED);
//	myList.addToEnd(dLED);
//	
//	
//	Serial.println(myList.listLength());
//	
//	for (int n=0;n<myList.listLength();n++)
//	{
//		myList.entry(n)->color.printVitals();
//	}
//	
//	myList.removeEntry(3);
//	
//	Serial.println(myList.listLength());
}

void Tester::ledColorMixingTest()
{
	LED brightRed;
	brightRed.color.setColor(LITColor.red);
	brightRed.brightness = 100;
	
	LED medBlue;
	medBlue.color.setColor(LITColor.blue);
	medBlue.brightness = 50;
	
	medBlue.mixWith(brightRed);
	
	medBlue.printVitals();
}

>>>>>>> ryanDev
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
	
<<<<<<< HEAD
	Serial.println("Dot");
	myDot.printVitals();
=======
	myHeadband.update();
	//myHeadband.printLEDs();
	//myHeadband.lights.printLEDs();
>>>>>>> ryanDev
	
	for (int n=0;n<myDot.numSegments();n++)
	{
		Serial.print(n);	Serial.print(" ");
		myDot.segments[n]->color.printVitals();
	}
	
	Serial.println("Alt");
	myAlt.printVitals();
	
	for (int n=0;n<myAlt.numSegments();n++)
	{
<<<<<<< HEAD
		Serial.print(n);	Serial.print(" ");
		myAlt.segments[n]->color.printVitals();
	}
	
	Serial.println("Snake");
	mySnake.printVitals();
	
	for (int n=0;n<mySnake.numSegments();n++)
	{
		Serial.print(n);	Serial.print(" ");
		mySnake.segments[n]->color.printVitals();
=======
		myHeadband.update();
		//myHeadband.printLEDs();
		//myHeadband.lights.printLEDs();
>>>>>>> ryanDev
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
	
//	for (int n=0;n<20;n++)
//	{
//		myHeadband.update();
//		myHeadband.printLEDs();
//	}
}




















