  

#include <SPI.h>
#include "Headband.h"

Headband headband;

//////////shift register code//////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////

//////////FHT code/////////////////////////////////////////////////////////////
#define LOG_OUT 1 // use the log output function
#define FHT_N 256 // set to 256 point fht
///////////////////////////////////////////////////////////////////////////////


#include <FHT.h> // include the library
void setup()
{
  Serial.begin(115200);
  ShiftPWM.SetAmountOfRegisters(numRegisters);
  ShiftPWM.Start(pwmFrequency,bright);
  
  //setup ADC for FHT
  TIMSK0 = 0; // turn off timer0 for lower jitter
  ADCSRA = 0xe5; // set the adc to free running mode
  ADMUX = 0x41; // use adc0
  DIDR0 = 0x00; // turn off the digital input for adc0
}

void loop()
{
  
  while(1) { // reduces jitter
    cli();  // UDRE interrupt slows this way down on arduino1.0
    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      while(!(ADCSRA & 0x10)); // wait for adc to be ready
      ADCSRA = 0xf5; // restart adc
      byte m = ADCL; // fetch adc data
      byte j = ADCH;
      int k = (j << 8) | m; // form into an int
      k -= 0x0200; // form into a signed int
      k <<= 6; // form into a 16b signed int
      fht_input[i] = k; // put real data into bins
    }
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_log(); // take the output of the fht
    sei();
    Serial.write(255); // send a start byte
    Serial.write(fht_log_out, FHT_N/2); // send out the data
    headband.update();
    doSRs();
  }
}

void doSRs()
{
  for (int n=0;n<numLEDs;n++)
  {
    SRTrio trip = sr3(n);
    ShiftPWM.SetRGB(n,trip.srR,trip.srG,trip.srB); 
  }
}
