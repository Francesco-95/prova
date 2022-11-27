#include "BarScroll.h"
#include "FastLED.h"

#define DinPin 5
#define N_LED 60
CRGB LED[N_LED];

#define R_Bar 4
#define C_Bar 11
BarScroll bar(C_Bar, R_Bar, LED);

byte Gs[]={B00001};

int Col[3]={0,0, 100}; // R G B
//int r=0, g=10, b=0;
  
void setup(){  
  Serial.begin(9600);
  FastLED.addLeds <WS2812, DinPin, RGB> (LED, N_LED); 
  }
  
void loop(){
  //bar.pixel(0,0, Col);
  bar.DrowSprite (0,0, 0, 0, Gs , Col);
}
