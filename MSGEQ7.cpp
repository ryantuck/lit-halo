//	####################################################################
//
//	MSGEQ7.cpp
//
//	####################################################################

#include "MSGEQ7.h"

MSGEQ7::MSGEQ7()
{
	analogPin	= 6;
	strobePin	= 9;
	resetPin	= 8;
	
	pinMode(analogPin,	INPUT);
	pinMode(strobePin,	OUTPUT);
	pinMode(resetPin,	OUTPUT);
	
	analogReference(DEFAULT);
	
	digitalWrite(resetPin,	LOW);
	digitalWrite(strobePin, HIGH);
	
	for (int n=0;n<7;n++)
		spectrum[n] = 0;
}

void MSGEQ7::sample()
{
	digitalWrite(resetPin,HIGH);
	digitalWrite(resetPin,LOW);
	
	for (int n=0;n<7;n++)
	{
		digitalWrite(strobePin,LOW);
		delayMicroseconds(30);
		spectrum[n] = analogRead(analogPin);
		digitalWrite(strobePin,HIGH);
	}
	
//	for (int n=0;n<7;n++)
//	{
//		Serial.print(spectrum[n]);
//		Serial.print(" ");
//	}
//	Serial.println();
}

int MSGEQ7::spectrumSum()
{
	int tmpSum = 0;
	
	for (int n=0;n<7;n++)
		tmpSum += spectrum[n];
	
	return tmpSum;
}

int MSGEQ7::spectrumAvg()
{
	return spectrumSum()/7;
}

int MSGEQ7::spectrumMax()
{
	int tmpMax = 0;
	
	for (int n=0;n<7;n++)
		if (spectrum[n] > tmpMax)
			tmpMax = spectrum[n];
	
	return tmpMax;
}

int MSGEQ7::spectrumMin()
{
	int tmpMin = 1024;
	
	for (int n=0;n<7;n++)
		if (spectrum[n] < tmpMin)
			tmpMin = spectrum[n];
	
	return tmpMin;
}

void MSGEQ7::subtractBaseline(int baseline)
{
	for (int n=0;n<7;n++)
	{
		if (spectrum[n] < baseline)
			spectrum[n] = 0;
		else
			spectrum[n] -= baseline;
	}
}


byte MSGEQ7::maxBand()
{
	byte tmpMaxBand = 0;
	
	for (int n=0;n<7;n++)
		if (spectrum[n] > spectrum[tmpMaxBand])
			tmpMaxBand = n;
	
	return tmpMaxBand;
}

byte MSGEQ7::minBand()
{
	byte tmpMinBand = 0;
	
	for (int n=0;n<7;n++)
		if (spectrum[n] < spectrum[tmpMinBand])
			tmpMinBand = n;
	
	return tmpMinBand;
}

float MSGEQ7::centroid()
{
	float tmpSum = 0;
	
	for (int n=0;n<7;n++)
	{
		tmpSum += n * spectrum[n];
	}
	
	return tmpSum / spectrumSum();
}





















