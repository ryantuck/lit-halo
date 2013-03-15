//	####################################################################
//
//	Arduino.h
//
//	*	Placeholder file so compiler doesn't complain.
//
//	####################################################################

#ifndef __cppTesting__Arduino__
#define __cppTesting__Arduino__

#include "Serial.h"
#include "SPI.h"

#define LOW			0
#define HIGH		1

#define INPUT		1
#define OUTPUT		2
#define DEFAULT		3

#define A2			3
#define MSBFIRST	0
#define LSBFIRST	1


typedef int byte;

inline void	digitalWrite(int a, int b){};
inline void	pinMode(int a, int b){};
inline void	analogReference(int a){};
inline void	delayMicroseconds(int a){};
inline int	analogRead(int a){return 0;};
inline int	digitalRead(int a){return 1;};
inline void shiftOut(int a,int b,int c, int d);
inline int millis(){return 1;};

extern SPIClass SPI;
extern SerialClass Serial;

#endif
