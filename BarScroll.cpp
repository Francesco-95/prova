#include<Arduino.h>
#include "BarScroll.h"
#include "FastLED.h"
#include "sprite.h"

BarScroll::BarScroll(int c, int r, CRGB *LED){
  this->ColumnBar=c;
  this->RowBar=r;
  this->LED=LED;
}

// --- Accensione led tramite cordinate righe e colonne e passandogli il colore ---
void BarScroll::pixel (int column, int row, int colore[3]){
  if (row > RowBar){
    row=RowBar;
    }

  if (column > ColumnBar){
    column=ColumnBar;
    }

  int c = column + (row * (ColumnBar+1));
  Serial.print (c);
  this->LED[c]=CRGB (colore[1], colore[0], colore[2]);
  FastLED.show();
  }

//dimSpriteR -> Dimensione Disegno Sprite Righe in Pixel
//dimSpriteC -> Dimensione Disegno Sprite Colonne in Pixel
//r_s -> Spostamento lungo le righe dello Sprite
//c_s -> Spostamento lungo le colonne dello Sprite

  void BarScroll::DrowSprite (int dimSpriteR, int dimSpriteC, int r_s,int c_s, byte s[], int colore[3]) {
    pixel(dimSpriteC, dimSpriteR, colore[3]);
  }
