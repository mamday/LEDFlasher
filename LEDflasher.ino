#include "SPI.h"
#include "C:\Program Files (x86)\Arduino\libraries\WS2801\WS2801.h"

/***************************************************************
 This sketch will allow you to manipulate the color of a single 
 LED.
  To change the color and LED do the following:

  1) Select an intensity of RED on a scale of 0-100.
  2) Select an intensity of GREEN on a scale of 0-100.
  3) Select an intensity of BLUE on a scale of 0-100.
  
  4) Select an LED to turn on. There are 20 of them
     numbered 0-19.
  
  5) Select the rate of the flash in milli-seconds
  
  6) Click the Upload button (the right arrow).
***************************************************************/
//Select the intensity of Red, Green and Blue
int Red=200;  
int Green=0;  
int Blue=0; 
// Select the LED you what turned on (1-20)
int LED=14;
// Select the time of the flash in milli-seconds
int Time=105;
//
/***************************************************************/
//
//
//
//
// Define strip
//
int dataPin = 2;
int clockPin = 3;
int NPixels = 20;
int RedOff=0;
int GreenOff=0;
int BlueOff=0;

//
WS2801 strip = WS2801(NPixels, dataPin, clockPin);
//
// Setup strip so all LEDs start turned off
//
void setup() {
  strip.begin();
  strip.show();
}
//
// Loop over the current settings until the sketch is loaded again.
//
void loop() { //sets to color of one pixel
  setOnePixel(LED, Red, Green, Blue);
  delay(Time);
  setOnePixel(LED, RedOff, GreenOff, BlueOff);
  delay(Time);
}
//
// Loop over the current settings until the sketch is loaded again.
//
void dgloloop() { //sets to color of one pixel
  for (int i = 1; i <= 20; i++) {
    setOnePixel(i, Red, Green, Blue);
    delay(Time/10);
    setOnePixel(i, RedOff, GreenOff, BlueOff);
    delay(Time);
  }
}
//
// define the on pixel function
//
void setOnePixel(int LED, int Red, int Green, int Blue) {
  //
  // Rescale color choices to be in (0,255)
  //
  int Red1=(int)Red*2.55;
  int Green1=(int)Green*2.55;
  int Blue1=(int)Blue*2.55;
  strip.setPixelColor(LED,Color(Red1, Green1, Blue1));

  strip.show();
}
//
// Create a 24 bit color value from R,G,B
//
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}


