/*Code Sources:
Arcada graphicstest (Display, Buttons)

*/

#include "Adafruit_Arcada.h"
Adafruit_Arcada arcada;

#define WHITELED 43

void setup(void) {
  Serial.begin(9600);
  arcada.arcadaBegin();
  arcada.displayBegin();
  arcada.setBacklight(255);
  arcada.display->fillScreen(ARCADA_BLACK);
  arcada.display->setTextColor(ARCADA_WHITE);
  pinMode(WHITELED, OUTPUT);
  digitalWrite(WHITELED, LOW);
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
      
  winstatus = 2;
  windisplay(winstatus);
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
    for (int i=1;i<5;i++) {   
      digitalWrite(WHITELED, 1);
      delay(500);
      digitalWrite(WHITELED, LOW);
      delay(500);            
    }
    winstatus = 0;       
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
    tone(ARCADA_AUDIO_OUT, 2000, 100);
    winstatus = 0;
  }
}