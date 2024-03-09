#include "displaytft.h"

Tft::Tft(int CS, int DC, int RST){
  this->CS_PIN=CS;
  this->DC_PIN=DC;
  this->RST_PIN=RST;
  delay(500);
  }

void Tft::setup_tft(int r){
  tft.init(240, 320);
  tft.setRotation(1);
  delay(1000);
  tft.setCursor(0, 0);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextWrap(true);
    tft.print("Attivazione SPIFFS fallita");
  }
