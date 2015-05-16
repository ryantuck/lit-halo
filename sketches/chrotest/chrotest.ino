
#include <Adafruit_NeoPixel.h>

#define pin 13
#define num_pixels 12

#define b1 25

Adafruit_NeoPixel strip = Adafruit_NeoPixel(num_pixels, pin, NEO_GRB + NEO_KHZ800);

int lastButtonState = 0;

bool pressed = false;
bool released = false;

int color = 0;

void setup()
{
  // serial stuff
  Serial.begin(9600);
  
  pinMode(b1,INPUT);   
  // strip stuff
  strip.begin();
  strip.show();
  Serial.println('yo dude');
}

void loop()
{ 
  int r = 20;
  int g = 20;
  int b = 20;

 
  checkState();
  if (pressed) {
    Serial.println('pressed');
    color = (color + 1) % 3; 
  }
  
  switch (color) {
      case 0:
        r = 100;
/g = 0;
        b = 0;
        break;
      case 1:
        r = 0;
        g = 100;
        b = 0;
        break;
      case 2:
        r = 0;
        g = 0;
        b = 100;
        break;
    }
    
  for (int i=0; i<num_pixels; i++)
  {
    strip.setPixelColor(i,r,g,b);
  }  
  
  strip.show();
  
  delay(50);
}


void checkState()
{
  bool reading = digitalRead(b1);

    if(reading != lastButtonState)
    {
        if(!reading) pressed = 1;
        if(reading) released = 1;
    }
    else
    {
        pressed		= 0;
        released	= 0;
    }
    lastButtonState = reading;

}
