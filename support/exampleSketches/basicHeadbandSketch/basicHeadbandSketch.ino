//  Barebones headband sketch
//    This is essentially what our final sketch will look like.

#include <SPI.h>
#include "Hardware.h"

Headband myHeadband;

void setup()
{
  myHeadband.linkUp();
}

void loop()
{
  myHeadband.update();
}


