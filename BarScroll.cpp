#include <Arduino.h>
#include "BarScroll.h"
#include <FastLED.h>
#include "sprite.h"

BarScroll::BarScroll(int c, int r, CRGB *LED){
  this->ColumnBar=c;
  this->RowBar=r;
  this->LED=LED;
}

// --- Accensione led tramite cordinate righe e colonne e passandogli il colore ---
void BarScroll::pixel (int column, int row, int R, int G, int B){
  if (row > RowBar){
    row=RowBar;
    }

  if (column > ColumnBar){
    column=ColumnBar;
    }

  int c = column + (row * (ColumnBar+1));
  this->LED[c]=CRGB (G,R,B);
  FastLED.show();
  }

//dimSpriteR -> Dimensione Disegno Sprite Righe in Pixel
//dimSpriteC -> Dimensione Disegno Sprite Colonne in Pixel
//r_s -> Spostamento lungo le righe dello Sprite
//c_s -> Spostamento lungo le colonne dello Sprite
     
 void BarScroll::DrowSprite (int dimSpriteR, int dimSpriteC, int r_s,int c_s, byte s[], int R,int G,int B) {
    for (int c=dimSpriteC; c>=0; c--){
      for (int r=dimSpriteR; r>=0; r--){
        bool pix= s[c] & (B10000 >> r);
        if (pix){
          pixel (c_s+c, r_s+r, R,G,B);
         } else {
          pixel (c_s+c, r_s+r, 0,0,0);
         }
      } 
    }
  }

void BarScroll::DrowBar (byte s[], int R, int G, int B) {
  for (int c=ColumnBar; c>=0; c--){
      for (int r=RowBar; r>=0; r--){
        bool pix= s[c] & (B10000 >> r);
        if (pix){
          pixel (c, r, R,G,B);
         } else {
          pixel (c, r, 0,0,0);
         }
      } 
    }
}

void BarScroll::off(){
  for (int i=0; i<((RowBar+1)*(ColumnBar+1)); i++){
    this->LED[i]=CRGB(0,0,0);
    }
  }

// str        -> Stringa da visualizzare
// dim_let    -> Dimensione lettera
// sprite_bar -> Array che rapresenta la barra
void BarScroll::Scrool(byte sprite_bar[], String str, int R, int G, int B){
  for (int i=ColumnBar; i>=0;i--){
    if (i==ColumnBar){
      pc=sprite_bar[i];
      sprite_bar[i]=get_colon(str);
      } else {
        ppc=sprite_bar[i];
        sprite_bar[i]=pc;
        pc=ppc;
      }
   }
    DrowBar (sprite_bar, R, G, B);
    delay (100);
    off();
}

byte BarScroll::get_colon(String str) {
  byte ris;
  str.toUpperCase();
  
  switch (str[pos_str]){

    case ' ':
      ris=space[0];
      if (pos_byte>=1){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;
    
    case 'A':
      ris=A[pos_byte];
      if (pos_byte>=sizeof(A)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;
    
    case 'B':
      ris=B[pos_byte];
      if (pos_byte>=sizeof(B)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;
   
   case 'C':
      ris=C[pos_byte];
      if (pos_byte>=sizeof(C)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;
   
   case 'D':
      ris=D[pos_byte];
      if (pos_byte>=sizeof(D)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'E':
      ris=E[pos_byte];
      if (pos_byte>=sizeof(E)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'F':
      ris=F[pos_byte];
      if (pos_byte>=sizeof(F)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'G':
      ris=G[pos_byte];
      if (pos_byte>=sizeof(G)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

      case 'H':
      ris=H[pos_byte];
      if (pos_byte>=sizeof(H)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'I':
      ris=I[pos_byte];
      if (pos_byte>=sizeof(I)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;  

     case 'J':
      ris=J[pos_byte];
      if (pos_byte>=sizeof(J)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'K':
      ris=K[pos_byte];
      if (pos_byte>=sizeof(K)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

   case 'L':
      ris=L[pos_byte];
      if (pos_byte>=sizeof(L)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'M':
      ris=M[pos_byte];
      if (pos_byte>=sizeof(M)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'N':
      ris=N[pos_byte];
      if (pos_byte>=sizeof(N)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'O':
      ris=O[pos_byte];
      if (pos_byte>=sizeof(O)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

   case 'P':
      ris=P[pos_byte];
      if (pos_byte>=sizeof(P)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

   case 'Q':
      ris=Q[pos_byte];
      if (pos_byte>=sizeof(Q)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

   case 'R':
      ris=R[pos_byte];
      if (pos_byte>=sizeof(R)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

   case 'S':
      ris=S[pos_byte];
      if (pos_byte>=sizeof(S)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'T':
      ris=T[pos_byte];
      if (pos_byte>=sizeof(T)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'U':
      ris=U[pos_byte];
      if (pos_byte>=sizeof(U)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'V':
      ris=V[pos_byte];
      if (pos_byte>=sizeof(V)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

     case 'W':
      ris=W[pos_byte];
      if (pos_byte>=sizeof(W)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'X':
      ris=X[pos_byte];
      if (pos_byte>=sizeof(X)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

    case 'Y':
      ris=Y[pos_byte];
      if (pos_byte>=sizeof(Y)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;

   case 'Z':
      ris=Z[pos_byte];
      if (pos_byte>=sizeof(Z)/sizeof(byte)){
        ris=space[0];
        pos_byte=0;
        pos_str++;
      } else {
        pos_byte++;    
      }
      break;
    };
  
  //  Se sforiamo la lunghezza torna indietro
  if (pos_str >= str.length()) {
    pos_str = 0;
  }
  return ris;
  }
