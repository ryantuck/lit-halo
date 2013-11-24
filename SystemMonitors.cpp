//	########################################################################

//  SystemMonitors.cpp

//	11/24/13

//	########################################################################

#include "SystemMonitors.h"

BinaryValue::BinaryValue()
{
	val = 0;
	start = 0;
	
	for (int n=0;n<10;n++)
	{
		int addr = start+n;
		
		addLEDs(LITColor.red, maxBrightness,addr,addr);
	}
	
	Step<BinaryValue>* myStep = new Step<BinaryValue>;
	myStep->fnPtr = &BinaryValue::display;
	myStep->period = 4;
	addStep(myStep);
}

BinaryValue::BinaryValue(int aStart)
{
	val = 0;
	start = aStart;
	
	for (int n=0;n<10;n++)
	{
		int addr = start+n;
		
		addLEDs(LITColor.red, maxBrightness,addr,addr);
	}
	
	Step<BinaryValue>* myStep = new Step<BinaryValue>;
	myStep->fnPtr = &BinaryValue::display;
	myStep->period = 4;
	addStep(myStep);
}

void BinaryValue::display()
{
	changeLEDs(val);
}

void BinaryValue::cycle()
{
	changeLEDs(val);
	val++;
	if (val >= 1024) val = 0;
}

void BinaryValue::changeLEDs(int newVal)
{
	// first set all LEDs to red (0)
	for (int n=0;n<countLEDs();n++)
	{
		fLEDs.entry(n)->me->color.setColor(LITColor.red);
	}
	
	
	// then go through newVal and change to green if 1
	for (int n=0;n<countLEDs();n++)
	{
		int threshold = pow(2,9-n);
		
		if (newVal >= threshold)
		{
			fLEDs.entry(n)->me->color.setColor(LITColor.green);
			newVal -= threshold;
		}
	}
}

DoubleMonitor::DoubleMonitor()
{
	Step<DoubleMonitor>* myStep = new Step<DoubleMonitor>;
	myStep->fnPtr = &DoubleMonitor::checkValues;
	myStep->period = 200;
	addStep(myStep);
	
	BinaryValue* battMonitor = new BinaryValue(0);
	BinaryValue* voltMonitor = new BinaryValue(16);
	
	addFoo(battMonitor);
	addFoo(voltMonitor);
	
}

void DoubleMonitor::checkValues()
{
	int battVoltage = analogRead(0);
	int threeV = analogRead(7);
	
	BinaryValue* bPtr = (BinaryValue*)foos.entry(0)->me;
	BinaryValue* vPtr = (BinaryValue*)foos.entry(1)->me;
	
	bPtr->val = battVoltage;
	vPtr->val = threeV;
}