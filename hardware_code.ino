#include <Adafruit_Crickit.h>
#include <Adafruit_miniTFTWing.h>
#include <Adafruit_NeoKey_1x4.h>
#include <Adafruit_NeoTrellis.h>
#include <Adafruit_seesaw.h>
#include <Adafruit_TFTShield18.h>
#include <seesaw_motor.h>
#include <seesaw_neopixel.h>
#include <seesaw_servo.h>
#include <seesaw_spectrum.h>
Adafruit_NeoKey_1x4 neokey;
/*Code Sources:
Arcada graphicstest (Display, Buttons)
*/

#include "Adafruit_Arcada.h"
Adafruit_Arcada arcada;

#define WHITELED 43

//define a callback for key presses
NeoKey1x4Callback blink(keyEvent evt) {
  uint8_t key = evt.bit.NUM;
  
  if (evt.bit.EDGE == SEESAW_KEYPAD_EDGE_RISING) {
    Serial.print("Key press ");
    Serial.println(key);
    neokey.pixels.setPixelColor(key, Wheel(map(key, 0, neokey.pixels.numPixels(), 0, 255)));
    
  } else if (evt.bit.EDGE == SEESAW_KEYPAD_EDGE_FALLING) {
    Serial.print("Key release ");
    Serial.println(key);

    neokey.pixels.setPixelColor(key, 0);
  }

  // Turn on/off the neopixels!
  neokey.pixels.show();
  return 0;
}


void setup(void) {
  Serial.begin(9600);
  arcada.arcadaBegin();
  arcada.displayBegin();
  arcada.setBacklight(255);
  arcada.display->fillScreen(ARCADA_BLACK);
  arcada.display->setTextColor(ARCADA_WHITE);
  pinMode(WHITELED, OUTPUT);
  digitalWrite(WHITELED, LOW);
  //-------------------------------------------
  //For Neo Key
   Serial.begin(115200);
  while (! Serial) delay(10);
   
  if (! neokey.begin(0x30)) {     // begin with I2C address, default is 0x30
    Serial.println("Could not start NeoKey, check wiring?");
    while(1) delay(10);
  }
  
  Serial.println("NeoKey started!");

  // Pulse all the LEDs on to show we're working
  for (uint16_t i=0; i<neokey.pixels.numPixels(); i++) {
    neokey.pixels.setPixelColor(i, 0x808080); // make each LED white
    neokey.pixels.show();
    delay(50);
  }
  for (uint16_t i=0; i<neokey.pixels.numPixels(); i++) {
    neokey.pixels.setPixelColor(i, 0x000000);
    neokey.pixels.show();
    delay(50);
  }
}

void loop() {
  
  int winstatus = 0;
  
  //stores button presses
  uint8_t buttons_pressed = arcada.readButtons();
  //displays current cards
  carddisplay();
  //if button B is pushed, display the card counter
  if (buttons_pressed & ARCADA_BUTTONMASK_B) {
    counterdisplay();
  }
  
  //if button a is pushed, remove the card counter
  //TODO: see if there is a way to remove the text



  if (buttons_pressed & ARCADA_BUTTONMASK_A) {
    arcada.displayBegin();
    arcada.setBacklight(255);
    arcada.display->fillScreen(ARCADA_BLACK);
    arcada.display->setTextColor(ARCADA_WHITE);
    carddisplay();
  }

 // if (winstatus ==0){
 // winstatus = 0;
     
  
 //---------------------------
 uint8_t buttons = neokey.read();

  // Check each button, if pressed, light the matching neopixel
  
  if (buttons & (1<<0)) {
    Serial.println("Button A");
    neokey.pixels.setPixelColor(0, 0xFF0000); // red
    counterdisplay();
  } else {
    neokey.pixels.setPixelColor(0, 0);
  }

  if (buttons & (1<<1)) {
    Serial.println("Button B");
    neokey.pixels.setPixelColor(1, 0xFFFF00); // yellow
  } else {
    neokey.pixels.setPixelColor(1, 0);
  }
  
  if (buttons & (1<<2)) {
    Serial.println("Button C");
    neokey.pixels.setPixelColor(2, 0x00FF00); // green
  } else {
    neokey.pixels.setPixelColor(2, 0);
  }

  if (buttons & (1<<3)) {
    Serial.println("Button D");
    neokey.pixels.setPixelColor(3, 0x00FFFF); // blue
  } else {
    neokey.pixels.setPixelColor(3, 0);
  }  

  neokey.pixels.show();
  
  delay(10);
  windisplay(winstatus);
}
// Input a value 0 to 255 to get a color value.
// The colors are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return seesaw_NeoPixel::Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return seesaw_NeoPixel::Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return seesaw_NeoPixel::Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  return 0;
}
void carddisplay() {
  arcada.display->setTextSize(2);
  arcada.display->setCursor(0,0); 
  arcada.display->println("Dealer:");
  arcada.display->setCursor(0,15);
  arcada.display->println("4C  KD  7S");
  arcada.display->setCursor(0,30);
  arcada.display->println("------------");
  arcada.display->setCursor(0,50);
  arcada.display->println("Your Cards:");
  arcada.display->setCursor(0,75);
  arcada.display->println("9D");
  arcada.display->setCursor(0,95);
  arcada.display->println("3H");
  arcada.display->setCursor(0,115);
  arcada.display->println("5S");
  arcada.display->setCursor(0,135);
  arcada.display->println("2C");    
  arcada.display->setCursor(160,50);       
  arcada.display->println("Split:");
  arcada.display->setCursor(160,75);
  arcada.display->println("9H");
  arcada.display->setCursor(160,95);
  arcada.display->println("10S");
  arcada.display->setCursor(160,115);
  arcada.display->println("QH");

  arcada.display->setCursor(0,165);
  arcada.display->println("---");
  arcada.display->setCursor(0,180);
  arcada.display->println("19");
  arcada.display->setCursor(160,165);
  arcada.display->println("---");
  arcada.display->setCursor(160,180);
  arcada.display->println("29");
}

void counterdisplay() {
  arcada.display->setCursor(80,200);
  arcada.display->println("Card Counter:");
  arcada.display->setCursor(140,220);
  arcada.display->println("0");
}

void windisplay(int winstatus) {
  if (winstatus == 1) {
    arcada.displayBegin();
    arcada.setBacklight(255);
    arcada.display->fillScreen(ARCADA_WHITE);
    arcada.display->setTextColor(ARCADA_GREEN);
    arcada.display->setTextSize(6);
    arcada.display->setCursor(0,100);
    arcada.display->println("You Win!");

    //winstatus = 0;  
     neokey.pixels.setPixelColor(0, 0x00FF00); // red
    neokey.pixels.setPixelColor(1, 0x00FF00); // red

    neokey.pixels.setPixelColor(2, 0x00FF00); // red
    neokey.pixels.setPixelColor(3, 0x00FF00); // 
    neokey.pixels.show();     
  }
  if (winstatus == 2) {
    arcada.displayBegin();
    arcada.setBacklight(255);
    arcada.display->fillScreen(ARCADA_WHITE);
    arcada.display->setTextColor(ARCADA_RED);
    arcada.display->setTextSize(6);
    arcada.display->setTextSize(5);
    arcada.display->setCursor(0,100);
    arcada.display->println("You Lose!");
    
    neokey.pixels.setPixelColor(0, 0xFF0000); // red
    neokey.pixels.setPixelColor(1, 0xFF0000); // red

    neokey.pixels.setPixelColor(2, 0xFF0000); // red
    neokey.pixels.setPixelColor(3, 0xFF0000); // 
    neokey.pixels.show();
    //tone(ARCADA_AUDIO_OUT, 2000, 100);
   // winstatus = 0;
  }
}
