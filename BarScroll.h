#ifndef  _BARSCROLL.h_
#define _BARSCROLL.h_

#include<Arduino.h>
#include <FastLED.h>

class BarScroll{
  private:
    int RowBar, ColumnBar; 
    int off_led[3] = {0,0,0};
    CRGB *LED;
    byte c, pc, ppc;
    int pos_str = 0;
    int pos_byte = 0;
   
  public:
    //  Inizializzazione della classe
    BarScroll(int c, int r, CRGB *LED); 

    //  Accendi il led in base a colonne (column) e righe (row) e colori (RGB)
    void pixel (int column, int row, int R, int G, int B);

    //  Disegna un array di byte (s) di colonne (dimSpriteC) e righe (dimSpriteR) con uno spostamento di righe (r_s) e colonne (c_s) e colori (RGB)
    /* byte Gs[]={
        B11110,
        B00101,
        B00101,
        B11110,
      };*/
    void DrowSprite (int dimSpriteR, int dimSpriteC, int r_s,int c_s, byte s[], int R, int G, int B);

    //  Disegna un array di byte (s) delle dimensioni della barra e colori (RGB)
    void DrowBar (byte s[], int R, int G, int B);

    //  Spegne tutti i led
    void off();
    
    //  Scorrimento barra led
    void Scrool(byte sprite_bar[], String str, int R, int G, int B);

    //  Apprendi da ciò che vuoi scrivere sulla barra led
    byte get_colon(String str);
    
};


#endif
