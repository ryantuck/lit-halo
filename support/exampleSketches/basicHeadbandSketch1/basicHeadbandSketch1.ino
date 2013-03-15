//  Barebones headband sketch
//    This is essentially what our final sketch will look like.

#include <SPI.h>
#include "Headband.h"

Headband myHeadband;

void setup()
{
  Serial.begin(19200);
  myHeadband.linkUp();
}

void loop()
{
  myHeadband.update();
}


