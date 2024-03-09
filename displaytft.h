#ifndef DISPLAYTFT.h
#define DISPLAYTFT.h
#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPIFFS_ImageReader.h>
//#include  <Fonts/FreeSerif9pt7b.h>

class Tft {
  private:
  int CS_PIN, DC_PIN, RST_PIN;
  Adafruit_ST7789 tft = Adafruit_ST7789(CS_PIN, DC_PIN, RST_PIN);
  
  public:
  Tft(int CS, int DC, int RST);
  void setup_tft(int r);
  };

#endif
