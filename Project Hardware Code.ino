/*Code Sources:
Arcada graphicstest (Display, Buttons)

*/

#include "Adafruit_Arcada.h"
Adafruit_Arcada arcada;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "game.c"
#include<unistd.h>

void setup(void) {
  Serial.begin(9600);
  arcada.arcadaBegin();
  arcada.displayBegin();
  arcada.setBacklight(255);
  arcada.display->fillScreen(ARCADA_BLACK);
  arcada.display->setTextColor(ARCADA_WHITE);
}

void loop() {
  //stores button presses
  //uint8_t buttons_pressed = arcada.readButtons();
    arcada.displayBegin();
    arcada.setBacklight(255);
    arcada.display->fillScreen(ARCADA_WHITE);
    delay(5000);
  //main();
  //displays current cards
  //carddisplay();
  //if button B is pushed, display the card counter
//   if (buttons_pressed & ARCADA_BUTTONMASK_B) {
//     counterdisplay(current_count);
//   }
//   //if button a is pushed, remove the card counter
//   if (buttons_pressed & ARCADA_BUTTONMASK_A) {
//     arcada.displayBegin();
//     arcada.setBacklight(255);
//     arcada.display->fillScreen(ARCADA_BLACK);
//     arcada.display->setTextColor(ARCADA_WHITE);
//     //carddisplay();
//   }
}


//void carddisplay() {   
//size_t dealer_size = sizeof(dealer_hand)/sizeof(short);
//for(int i=0;i<dealer_size;i++) {  
//  arcada.display->setTextSize(2);
//  arcada.display->setCursor(0,0); 
//  arcada.display->println("Dealer:");
//  arcada.display->setCursor(0,15*i);
//  arcada.display->println(dealer_hand[i]);
//  arcada.display->println("------------");
//}
// size_t player_size = sizeof(player_hand)/sizeof(short);
// for(int i=0;i<player_size;i++) {
//   arcada.display->setCursor(0,50);
//   arcada.display->println("Your Cards:");
//   arcada.display->setCursor(0,60+15*i);
//   arcada.display->println(player_hand[i]);
//   arcada.display->setCursor(0,165);
//   arcada.display->println("---");
//   arcada.display->setCursor(0,180);
//   //arcada.display->println(player_total);
//   arcada.display->setCursor(160,165);
//   arcada.display->println("---");
//   arcada.display->setCursor(160,180);
//   //arcada.display->println(dealer_total);
// }
// }

// void counterdisplay() {
//   arcada.display->setCursor(80,200);
//   arcada.display->println("Card Counter:");
//   arcada.display->setCursor(140,220);
//   arcada.display->println(current_count);
// }

// void windisplay() {
//     arcada.displayBegin();
//     arcada.setBacklight(255);
//     arcada.display->fillScreen(ARCADA_WHITE);
//     arcada.display->setTextColor(ARCADA_GREEN);
//     arcada.display->setTextSize(6);
//     arcada.display->setCursor(0,100);
//     arcada.display->println("You Win!");      
// }
// void losedisplay() {
//     arcada.displayBegin();
//     arcada.setBacklight(255);
//     arcada.display->fillScreen(ARCADA_WHITE);
//     arcada.display->setTextColor(ARCADA_RED);
//     arcada.display->setTextSize(6);
//     arcada.display->setTextSize(5);
//     arcada.display->setCursor(0,100);
//     arcada.display->println("You Lose!");
// }
