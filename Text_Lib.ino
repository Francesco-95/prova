// Lib AP
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
// barra led
#include <FastLED.h>
#include "BarScroll.h"

// AP avvio server
AsyncWebServer server(80);
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

String Text_def="Loading...";
String Col_1="ff00ff";
String Col_2="#000000";
String Col_3="#000000";
String Col_4="#000000";

// Barra led
#define DinPin 5
#define N_LED 60
CRGB LED[N_LED];

#define R_Bar 4
#define C_Bar 11
BarScroll bar(C_Bar, R_Bar, LED);
byte sprite_bar[12]={B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // Vincolati per lo scorrimento della barra
// Disegno errore
byte sprite_er[9]={B11111,B10101,B10001,B00000,B11111,B00101,B01010,B10000,B00000};

int R_1, G_1, B_1;
int ConversioneColore (String col);
int ConvEsaInDec (char c);
String processor(const String& par);

void setup() {
  Serial.begin(115200);
  delay (2000);
  Serial.println("AP HTML"); 

  // AP
  WiFi.softAP("ESP32_Wifi", "Esp32Wifi");
  WiFi.softAPConfig (local_ip, gateway, subnet);
  delay(1000);

   // SPIFFS
  if (!SPIFFS.begin(true)){
    Serial.println("SPIFFS Error");
    while(1);
   }
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send(SPIFFS, "/index.html", String(), false, processor);  
  });
  
  server.on("/home.html", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send(SPIFFS, "/home.html", String(), false, processor);  
  });
  server.on("/text.html", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send(SPIFFS, "/text.html", String(), false, processor);  
  });
  server.on("/colore.html", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send(SPIFFS, "/colore.html", String(), false, processor);  
  });
  server.on("/fondatori.html", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send(SPIFFS, "/fondatori.html", String(), false, processor);  
  });
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send(SPIFFS, "/style.css", "text/css");  
  });

  server.on("/text_board", HTTP_GET, [](AsyncWebServerRequest *req){
    String inputMessage = req->getParam("text_board")->value();
    delay(100);
    Text_def=inputMessage;
    req->send(SPIFFS, "/colore.html", String(), false, processor); 
  });

  server.on("/Color", HTTP_GET, [](AsyncWebServerRequest *req){
    String inputMessage="";
      if (req->getParam("mul")){
        inputMessage="C_" + req->getParam("mul")->value();
        
      } else { 
        Col_1=req->getParam("a")->value();
        Col_2=req->getParam("b")->value();
        Col_3=req->getParam("c")->value();
        Col_4=req->getParam("d")->value();
        delay(100);
      }
      req->send(SPIFFS, "/home.html", String(), false, processor); 
  }); 
 
  server.begin();
  delay (1000);
  FastLED.addLeds <WS2812, DinPin, RGB> (LED, N_LED); 

  ConversioneColore (Col_1);
}

void loop() {
  bar.Scrool(sprite_bar, Text_def, R_1, G_1, B_1);
}

// Conversione stringa da esadecimale a RGB
int ConversioneColore (String col){
   R_1=(ConvEsaInDec (col[1])*16)+ConvEsaInDec (col[2]);
   G_1=(ConvEsaInDec (col[3])*16)+ConvEsaInDec (col[4]);
   B_1=(ConvEsaInDec (col[5])*16)+ConvEsaInDec (col[6]);
   Serial.println(R_1);
   Serial.println(G_1);
   Serial.println(B_1);
  }

// Conversione da numero in esadcimale in decimale
int ConvEsaInDec (char c){
  char conv_ex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
  int conv_dec[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  for (int i=0; i<=(sizeof(conv_ex)/sizeof(char)); i++){
    if (c == conv_ex[i]){
      return (conv_dec[i]);
      break;
      }
    }
    return 0;
  }

String processor(const String& par){
  return String ();
  }
