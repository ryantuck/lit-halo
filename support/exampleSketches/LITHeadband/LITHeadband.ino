  

#include <SPI.h>
#include "Headband.h"

Headband headband;

#define SHIFTPWM_NOSPI
const int  ShiftPWM_latchPin      = 3;  // can use just 'int'?
const int  ShiftPWM_dataPin       = 2;
const int  ShiftPWM_clockPin      = 4;
const bool ShiftPWM_invertOutputs = true;
const bool ShiftPWM_balanceLoad   = false;
#include "ShiftPWM.h"  // include after setting pins - should just set in lib?

unsigned char bright = 100;
unsigned char pwmFrequency = 75;
int numRegisters = 12;
int numRGBleds = 32;


void setup()
{
  Serial.begin(28800);
  ShiftPWM.SetAmountOfRegisters(numRegisters);
  ShiftPWM.Start(pwmFrequency,bright);
}

void loop()
{
  headband.update();
  doSRs();
}

void doSRs()
{
  for (int n=0;n<numLEDs;n++)
  {
    SRTrio trip = sr3(n);
    ShiftPWM.SetRGB(n,trip.srR,trip.srG,trip.srB); 
  }
}
