#ifndef  _BARSCROLL.h_
#define _BARSCROLL.h_

#include<Arduino.h>
#include "FastLED.h"

class BarScroll{
  private:
    int RowBar, ColumnBar; 
    int off_led[3] = {0,0,0};
    CRGB *LED;
    
  public:
    BarScroll(int c, int r, CRGB *LED);
    void pixel (int column, int row, int colore[3]);
    void DrowSprite (int dimSpriteR, int dimSpriteC, int r_s,int c_s, byte s[], int colore[3]);
};


#endif
